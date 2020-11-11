// edit by xgchen@fy 2002-2-9

#include <ansi.h>
#include <command.h>
#include <globals.h>
#include <net/daemons.h>
#include <net/macros.h>

int LAST_HARD_DIS= 0;
void init_cron();
void autosave();
void autodel();
void check_dns();
void check_pets();
void check_whonature();
void create()
{
        seteuid( ROOT_UID );
        init_cron();
}
int query_last_hard_dis()
{
        return LAST_HARD_DIS;
}
int set_last_hard_dis()
{
        LAST_HARD_DIS = time();
        return time();
}
void init_cron()

{

        mixed *local;
    object *users, present,npc;
    string *names = 
    ({
        "/obj/food/cj",
        "/obj/food/dan1",
        "/obj/money/gold",
        "/obj/money/gold",
    });
    int i;
 
     if( time()%(3600*8) == 1 )
         {
            users = users();
            i = sizeof(users);
            while(i--)
              {
                  present=new(names[random(sizeof(names))]);
                  present->move(users[i]);
                  tell_object(users[i],HIR "��ʦ�������ԩ�࣬����������Ʒ\n\n" +
                    HIW "���ϴ���һ�󶣶�����������\n\n" +
                    HIY "ͻȻ���������һ�¶���һ��ʲô������\n\n" NOR);
              }
         }


        local = localtime(time());
		// by tiandi һСʱˢ�����ϰ�
     if(  !((local[1])%60) )
		 {
			npc = new("/d/wiz/fyup/npc/highbuyer");
			users = users();
            i = sizeof(users);
			npc ->move(environment(users[random(i)]));

		 }
// every 45 mins, autosave every player
        if ( !((local[1])%55)) autosave();
// ��24Сʱ��ɾ������pk �Ĳ���
        if ( !((local[1])%58)) autodel();
// On average tasks get renewed every 30 mins
        if ( !random(30)) 
      TASK_D->init_dynamic_quest();
        

//How long the system will refresh all tasks. Added by Xgchen@fy
//--------------------------------------------------------------------
 if ( !((local[1])%60))
     {
        message("system", HIY "\n��ϵͳ��Ϣ��:"+BLINK HIR+" ϵͳ��������Ӻ����·���ʹ����\n"NOR,users());
        call_out("countdown", 20, 5);
}

//--------------------------------------------------------------------
//�޸����ϵ�һ���аٷֺź������(�������60����1Сʱ)�Ϳ����޸�task���·ֲ���ʱ������ˡ�
//above is add by Xgchen@fy
// Check pets that's lost heartbeat

        if( !(local[1]%20)) 
       if(!find_object(VOID_OB))
                call_other(VOID_OB,"???");
        check_pets();
// 15����ˢ��һ�� Xgchen@fy
        if ( !(local[1]%15)) 
        {
        check_dns();
// if WHO_D,NATURE_D dies restart them
        check_whonature();
        STATUS_D->write_list();
        }
 load_object("/u/guanwai/shop.c");
// load_object("/d/dali/bank1.c");
 load_object("/d/chenxiang/nanbank.c");
 load_object("/d/fy/nanbank.c");
load_object("/d/qianfo/yezhang.c");
load_object("/d/shenshui/gong.c");
load_object("/u/ghost/house3.c");
load_object("/d/tieflag/moonding.c");
load_object("/d/qianjin/jinge.c");


        call_out("init_cron", 60);      
}
void autodel()
{
  string *dir,*ppls;
 object *user;
 int i;
        user = users();
         message("channel:gab", HIG "\n��������Ϣ��:"+NOR+HIR+" ��ӭ��ҹ���"+HIY+" һ������ "+HIR+"ϣ��������������ҵ���Ȥ!\n"NOR,users());
        for(i=0; i<sizeof(user); i++) 
        user[i]->delete("OPK");
        message("channel:gab", HIG "\n��ϵͳ��Ϣ��:"+NOR+HIR+" ����Ĺ�����Ϣ����������Ҫ��<tune gab>�Ϳ��Բ��տ��� \n" NOR, users()); 
}
void autosave()
{
 object *user ;
 int i;
         user = users();
        message("channel:gab", HIY "\n��ϵͳ��Ϣ��:"+NOR+HIR+" ϵͳ��׼����¼��ĵ�����\n"NOR, users());
        for(i=0; i<sizeof(user); i++) 
        user[i]->save();
        message("channel:gab", HIY "\n��ϵͳ��Ϣ��:"+NOR+HIG+" ��ĵ����Ѿ�����¼�ˡ� \n" NOR, users()); 
}
void check_dns()
{
        mapping mud_list;
        mixed *muds;
        object dns;

        if(!dns = find_object(DNS_MASTER))
        // dns not started, not our problem
        return;
        mud_list = (mapping) DNS_MASTER->query_muds();
        muds=keys(mud_list);
        if(sizeof(muds)<= 1)
        { destruct(dns);
        call_other(DNS_MASTER,"???");
        }
        return;
}

void check_whonature()
{
        mixed *info;
        int i;
        object ob;
        int who=0, nature=0;
        info = call_out_info();
        for(i=0; i<sizeof(info); i++)
        {
        if( "/"+sprintf("%O",info[i][0]) == WHO_D ) who =1;
        if( "/"+sprintf("%O",info[i][0]) == NATURE_D ) nature=1;
        }
        if(!who)
        {
                if(ob=find_object(WHO_D)) destruct(ob);
                call_other(WHO_D,"???");        
        }
        if(!nature)
        {
                if(ob=find_object(NATURE_D)) destruct(ob);
                call_other(NATURE_D,"???");
        }
        return;
}

void check_pets()
{
int i;
object ob,*ob_list;
ob_list=children("/obj/pet");
for(i=0; i<sizeof(ob_list); i++) {
if( !ob = environment(ob_list[i]) ) continue;
ob->heal_up();
                }

return;
}

private void countdown(int min)
{
        min--;
        if( min ) 
        {
                call_out("countdown", 60, min);
        } 
        else {
     message("system",HIR "���·ֲ�����ʹ��������" NOR,users());
            TASK_D->init_dynamic_quest(1);
            message("system",HIG "����������ʹ���ֲ����\n" NOR,users());

        }
}
