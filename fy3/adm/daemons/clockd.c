// clock.c
// ��ʱ�����¼��� daemon ����
// root@xhc

inherit F_DBASE;
#include <ansi.h>
#include <login.h>
#include <localtime.h>
#include <net/daemons.h>

void auto_reboot();
void update_time();
void create() 
{
        update_time();
}

void update_time()
{
        remove_call_out("update_time");
        auto_reboot();      
        call_out("update_time", 180);
}

void auto_reboot()                             
{
        mixed *mTime;
        object *oUser, oLink_ob;
        int iI, iJ;

        mTime = localtime( time() );

        if ( !((mTime[3])%5)) 
        {
                message("system", HIR"��ϵͳ���顿"NOR+HIY"������root����"NOR+BLINK HIR"ϵͳ������������\n" NOR, users() );

                oUser = users();
                iI = sizeof(oUser);
                while( iI--) {
                        if( !oUser[iI]) continue;
                        if( !environment(oUser[iI]) ) continue;
                        oUser[iI]->save();
                        oLink_ob = oUser[iI]->query_temp("link_ob");
                        if( objectp(oLink_ob) ) oLink_ob->save();
                }
                message("system", HIW"�����̾��顿"NOR""HIC"���ĵ����Ѿ��Զ������ˡ�\n"NOR, users() );
                if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

                shutdown(0);
        }

                if ( !((mTime[3])%4) && !((mTime[2])%23) && !((mTime[1])%30))      // ��ǰ��ʮ���Ӿ���ʾ
                message("system", HIR"��ϵͳ���顿"NOR+HIY"������ADMIN����"NOR+HIR"���棡Ϊ��������ٶȣ�
                        ϵͳ��������������\n" NOR, users() );
}
