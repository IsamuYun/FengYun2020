// clock.c
// 定时出现事件的 daemon 函数
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
                message("system", HIR"【系统精灵】"NOR+HIY"绝世（root）："NOR+BLINK HIR"系统重新启动啦！\n" NOR, users() );

                oUser = users();
                iI = sizeof(oUser);
                while( iI--) {
                        if( !oUser[iI]) continue;
                        if( !environment(oUser[iI]) ) continue;
                        oUser[iI]->save();
                        oLink_ob = oUser[iI]->query_temp("link_ob");
                        if( objectp(oLink_ob) ) oLink_ob->save();
                }
                message("system", HIW"【存盘精灵】"NOR""HIC"您的档案已经自动储存了。\n"NOR, users() );
                if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

                shutdown(0);
        }

                if ( !((mTime[3])%4) && !((mTime[2])%23) && !((mTime[1])%30))      // 提前三十分钟警告示
                message("system", HIR"【系统精灵】"NOR+HIY"绝世（ADMIN）："NOR+HIR"警告！为提高运行速度，
                        系统将会重新启动！\n" NOR, users() );
}
