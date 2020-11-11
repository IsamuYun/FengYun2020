// join.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_app;
	int i;
	string *skname,file,temp,c_name;

	if( !arg ) return notify_fail("指令格式：join [cancel]|<对象>\n");

	if( me->query("group") ) 
		return notify_fail("加入别的社团之前，你必须先向目前的社团团长申请退出。\n");
            
	if( arg=="cancel" ) {
		old_app = me->query_temp("pending/join");
		if( !objectp(old_app) )
			return notify_fail("你现在并没有加入任何社团的意思。\n");
		write("你改变主意不想加入" + old_app->name() + "的社团了。\n");
		tell_object(old_app, me->name() + "改变主意不想加入你的社团了。\n");
		me->delete_temp("pending/join");
		return 1;
	}

	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("你想加入谁的社团？\n");

	if( ob==me ) return notify_fail("你到底想不想加入社团啊，别浪费时间。\n");

	if( ! ob->query("group") ) 
		return notify_fail(ob->name() + "没有自己的社团。\n");	
	if(  ob->query("grouptitle") != 1 )
		return notify_fail(ob->name() + "不是社团团长。\n");

	if( (object)ob->query_temp("pending/invite") == me ) 
	{
		message_vision("$N决定加入$n的社团"+ob->query("group")+"！！\n\n",me, ob);
		me->set("groupscore", 0);
	      me->set("group",ob->query("group"));
	      me->set("grouptitle",10);
	      me->set("grouplv",ob->query("grouplv"));
	   c_name = ob->query("group");
                      ob->delete_temp("pending/invite");
		tell_object(ob, "恭喜你加入社团！\n");
		file = "/data/group/"+c_name;
		temp = me->query("name");
       		write_file(file,"\n"+ temp);

		return 1;
	} 
	else
	 {
		old_app = me->query_temp("pending/join");
		if( ob==old_app )
			return notify_fail("你想加入" + ob->name() + "的社团，但是对方还没有答应。\n");
		else if( objectp(old_app) )
		 {
			write("你改变主意不想加入" + old_app->name() + "的社团了。\n");
			tell_object(old_app, me->name() + "改变主意不想加入你的社团了。\n");
		}

		message_vision("$N想要加入$n的社团。\n", me, ob);
		me->set_temp("pending/join", ob );
		if( userp(ob) ) {
			tell_object(ob, YEL "如果你允许" + me->name() + "加入社团，用 invite 指令。\n" NOR);
			return 1;
		}
	}
}


int help(object me)
{
        write(@HELP
指令格式 : join [cancel]|<对象>
 
这个指令能让你加入对方的社团。
 
HELP
        );
        return 1;
}
