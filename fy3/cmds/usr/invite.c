// invite.c by tiandi

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_rec;
	string file,temp,c_name;
	int i;

	if( !arg ) return notify_fail("指令格式：invite [cancel]|<对象>\n");
	if( !me->query("group"))
		return notify_fail("你还没有建立社团，你先建立一个再说吧。\n");

	if( arg=="cancel" ) {
		old_rec = me->query_temp("pending/invite");
		if( !objectp(old_rec) )
			return notify_fail("你现在并没有收任何人加入社团的意思。\n");
		write("你改变主意不想邀请" + old_rec->name() + "加入社团了。\n");
		tell_object(old_rec, me->name() + "改变主意不想邀请你入社团了。\n");
		me->delete_temp("pending/invite");
		return 1;
	}

	if( !(ob = present(arg, environment(me))) )
		return notify_fail("你想邀请谁加入自己的社团？\n");

	if( ob==me ) return notify_fail("你到底收不收人啊，别浪费时间。\n");

	if( ob->query("group")== me->query("group") ) 
		return notify_fail("对方已经是你的社团的人了。\n");
	if( ob->query("group") ) 
		return notify_fail("对方已经加入别的社团了。\n");

	if( !me->query("group"))
		return notify_fail("你还没有建立社团，你先建立一个再说吧。\n");
          if( userp(me) && (int) me->query("grouptitle")!= 1)
             	   return notify_fail("不是社团团长不能收人．\n");
            if(userp(me) && (me->query("grouplv")*5 < (int)me->query("groups")) )
		return notify_fail("以你社团目前的等级来看，社团人员已经达到上限。\n");
      
	if( (object)ob->query_temp("pending/join") == me )
	 {
	    ob->set("groupscore", 0);
	    ob->set("group",me->query("group"));
	    ob->set("grouptitle",10);
	    ob->set("grouplv",me->query("grouplv"));
	  c_name = me->query("group");
                    me->add("groups",1);
	    message_vision("$N同意$n加入"+me->query("group")+"。\n\n",me, ob);
          ob->delete_temp("pending/join");
	    me->delete_temp("pending/invite");
	    ob->delete_temp("pending/join");
	    tell_object( ob, sprintf("恭喜您成为%s的社员。\n", ob->query("group")));
		file = "/data/group/"+c_name;
		temp = ob->query("name");
       		write_file(file, "\n"+ temp);
          return 1;
	}
	 else
	 {
		old_rec = me->query_temp("pending/invite");
		if( ob==old_rec )
			return notify_fail("你想邀请" + ob->name() + "加入自己的社团，但是对方还没有答应。\n");
		else if( objectp(old_rec) ) {
			write("你改变主意不想邀请" + old_rec->name() + "加入社团了。\n");
			tell_object(old_rec, me->name() + "改变主意不想邀请你入社团了。\n");
		}

		me->set_temp("pending/invite", ob );
		message_vision("\n$N邀请$n加入社团。\n", me, ob);
		tell_object(ob, YEL "如果你愿意加入" + me->name() + "的社团"+me->query("group")+"，请用 join 指令。\n" NOR);
		return 1;
	}
}


int help(object me)
{
        write(@HELP
指令格式 : invite [cancel]|<对象>
 
这个指令能让你邀请对方加入自己的社团。
 
HELP
        );
        return 1;
}
