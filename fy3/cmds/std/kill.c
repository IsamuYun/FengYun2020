// kill.c

#include <ansi.h>
#define LOWER_LIMIT 500000
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj,ob;
	string *killer, callname;
	seteuid(getuid());
	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准战斗。\n");

	if( !arg )
		return notify_fail("你想杀谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj==me)
		return notify_fail("用 suicide 指令会比较快:P。\n");

	callname = RANK_D->query_rude(obj);
       if (me->query("jiebai") &&userp(obj)&& strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
              return notify_fail("喂！你昏了，他和你结拜过，不能杀他!\n");
 	if (me->query("marry") == obj->query("id"))
              return notify_fail("你真的这么狠心，连你老伴都杀？\n");
    if (me->query("level")<10 && userp(obj))
              return notify_fail("你还处在新手保护区！\n");
      if( userp(obj) && (int) obj->query("level") < 10 &&
              !me->query("licensed_to_kill"))
              return notify_fail("对手还处在新手保护区！\n");
	if( userp(obj)&&userp(me))
   log_file( "KILL_LOG", sprintf("(%s)
 %s tried to kill %s\n", ctime(time()), me->query("id"), obj->query("id")));

        obj->add_temp("kill/"+me->query("id"),1);

	message_vision("\n$N对著$n喝道：「" 
		+ callname + "！今日不是你死就是我活！」\n\n", me, obj);
        me->kill_ob(obj);
        me->set("killren",1);
	if( !userp(obj) )
                obj->kill_ob(me);
	else {
		obj->fight_ob(me);
		tell_object(obj, HIR "如果你要和" + me->name() 
			+ "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
	}
      if (!userp(me)) return 1;
    if (stringp(obj->query("marry"))){
    ob=present(obj->query("marry"),environment(me));
    if (ob && userp(ob) && living(ob) && ob!=me ){
        if (ob->query("gender")=="男性")
            message_vision(CYN"\n$N一声怒吼："+me->name()+"！你竟敢欺负俺老婆，我跟你拼了！\n\n"NOR, ob);
        else
            message_vision(CYN"\n$N娇喝一声："+me->name()+"！看来你不把咱夫妇放在眼里，看招！\n\n"NOR, ob);
        ob->kill_ob(me); me->fight_ob(ob);
    }
    }
    if( !stringp(callname=obj->query("family/family_name")))
        if( !stringp(callname=obj->query("friend")))
        return 1;
    ob=first_inventory(environment(me));
    while(ob){
        if( ob!=obj && ob->is_character() && !ob->is_corpse() && living(ob)){
//同门互助（玩家可不参与）
            if ( (string)ob->query("family/family_name")==callname && !ob->is_killing(me) && !userp(ob) ){
                message_vision(CYN"\n$N大怒："+me->name()+"！你竟敢谋害我的同门？看招！\n\n"NOR, ob);
                ob->kill_ob(me); me->kill_ob(ob);
            }
//拜把的兄弟互助 暂时不开放
//            if ((string)ob->query("friend")==callname  || (string)ob->query("friend")==obj->query("id") ){
//                message_vision(CYN"\n$N冷冷一笑："+me->name()+"！你要杀我拜把的兄弟，得先问问我！\n\n"NOR, ob);
//                ob->kill_ob(me); me->fight_ob(ob);
//            }
        }
        ob=next_inventory(ob);
    }
    return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : kill <人物>
 
这个指令让你主动开始攻击一个人物，并且□试杀死对方，kill 和 fight 最大的
不同在於双方将会真刀实枪地打斗，也就是说，会真的受伤。由於 kill 只需单方
面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，通常如果
对方是 NPC 的话，他们也会同样对你使用 kill。

当有人对你使用 kill 指令时会出现红色的字样警告你，对於一个玩家而言，如果
你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用法术除
外)。

其他相关指令: fight

有关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
 
