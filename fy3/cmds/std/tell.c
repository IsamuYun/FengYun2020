// tell.c

#include <ansi.h>
#include <net/dns.h>
#define NEW_PERIOD 32400
inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	string name, refuse_name;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
        if(me->query("chblk_on"))
                return notify_fail("你的频道被关了！\n");
	if((int)me->query("mud_age") < NEW_PERIOD)
		return notify_fail("你只可以使用（say）。\n");
	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		return 1;
	}
	obj = find_player(target);
        if(!obj || !me->visible(obj)) return notify_fail("没有这个人....。\n");
        if(obj->query_temp("block_msg/all")==1) return notify_fail("这个人已经失去知觉，不可以接受TELL的信息。\n");
        if(obj->query_temp("block_msg/all")==1) return notify_fail("这个人断线中,不可以接受TELL的信息。\n");
	name = (string) me->query("id");
	refuse_name = (string) obj->query("env/no_tell");
	if( !wizardp(me) && (refuse_name == "all" || refuse_name == name))
	return notify_fail("此人已关闭了ＴＥＬＬ频道。\n");
	    if (query_idle(obj)>180) write(YEL+obj->name(1)+"已经发呆"+query_idle(obj)/60+"分钟，看来不会马上回答你哟！\n"+NOR);
   if (in_edit(obj)) return notify_fail("但是，对方好像正在编辑档案！\n");
write(GRN "你告诉" + obj->name(1) + "：" + msg + "\n" NOR);
	tell_object(obj, sprintf( HIG "%s告诉你：%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)告诉你：%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s 告诉你：%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：tell <某人> <讯息>

你可以用这个指令和其他地方的使用者说话。

其他相关指令：reply
HELP
	);
	return 1;
}
