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
                  tell_object(users[i],HIR "巫师考虑民间冤苦，决定发放礼品\n\n" +
                    HIW "天上传来一阵叮叮当当的铃声\n\n" +
                    HIY "突然你觉得身上一下多了一样什么东西。\n\n" NOR);
              }
         }


        local = localtime(time());
		// by tiandi 一小时刷新马老板
     if(  !((local[1])%60) )
		 {
			npc = new("/d/wiz/fyup/npc/highbuyer");
			users = users();
            i = sizeof(users);
			npc ->move(environment(users[random(i)]));

		 }
// every 45 mins, autosave every player
        if ( !((local[1])%55)) autosave();
// 在24小时内删除当天pk 的参数
        if ( !((local[1])%58)) autodel();
// On average tasks get renewed every 30 mins
        if ( !random(30)) 
      TASK_D->init_dynamic_quest();
        

//How long the system will refresh all tasks. Added by Xgchen@fy
//--------------------------------------------------------------------
 if ( !((local[1])%60))
     {
        message("system", HIY "\n【系统消息】:"+BLINK HIR+" 系统将在五分钟后重新分配使命。\n"NOR,users());
        call_out("countdown", 20, 5);
}

//--------------------------------------------------------------------
//修改以上第一行中百分号后的数字(现在设的60代表1小时)就可以修改task重新分布的时间间间隔了。
//above is add by Xgchen@fy
// Check pets that's lost heartbeat

        if( !(local[1]%20)) 
       if(!find_object(VOID_OB))
                call_other(VOID_OB,"???");
        check_pets();
// 15分钟刷新一次 Xgchen@fy
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
         message("channel:gab", HIG "\n【最新消息】:"+NOR+HIR+" 欢迎大家光临"+HIY+" 一世风云 "+HIR+"希望大家能在这里找到乐趣!\n"NOR,users());
        for(i=0; i<sizeof(user); i++) 
        user[i]->delete("OPK");
        message("channel:gab", HIG "\n【系统消息】:"+NOR+HIR+" 这里的公共信息大家如果不需要请<tune gab>就可以不收看。 \n" NOR, users()); 
}
void autosave()
{
 object *user ;
 int i;
         user = users();
        message("channel:gab", HIY "\n【系统消息】:"+NOR+HIR+" 系统正准备记录你的档案。\n"NOR, users());
        for(i=0; i<sizeof(user); i++) 
        user[i]->save();
        message("channel:gab", HIY "\n【系统消息】:"+NOR+HIG+" 你的档案已经被记录了。 \n" NOR, users()); 
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
     message("system",HIR "重新分布所有使命。。。" NOR,users());
            TASK_D->init_dynamic_quest(1);
            message("system",HIG "。。。所有使命分布完毕\n" NOR,users());

        }
}
