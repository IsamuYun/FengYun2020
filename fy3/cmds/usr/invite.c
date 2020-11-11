// invite.c by tiandi

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_rec;
	string file,temp,c_name;
	int i;

	if( !arg ) return notify_fail("ָ���ʽ��invite [cancel]|<����>\n");
	if( !me->query("group"))
		return notify_fail("�㻹û�н������ţ����Ƚ���һ����˵�ɡ�\n");

	if( arg=="cancel" ) {
		old_rec = me->query_temp("pending/invite");
		if( !objectp(old_rec) )
			return notify_fail("�����ڲ�û�����κ��˼������ŵ���˼��\n");
		write("��ı����ⲻ������" + old_rec->name() + "���������ˡ�\n");
		tell_object(old_rec, me->name() + "�ı����ⲻ���������������ˡ�\n");
		me->delete_temp("pending/invite");
		return 1;
	}

	if( !(ob = present(arg, environment(me))) )
		return notify_fail("��������˭�����Լ������ţ�\n");

	if( ob==me ) return notify_fail("�㵽���ղ����˰������˷�ʱ�䡣\n");

	if( ob->query("group")== me->query("group") ) 
		return notify_fail("�Է��Ѿ���������ŵ����ˡ�\n");
	if( ob->query("group") ) 
		return notify_fail("�Է��Ѿ������������ˡ�\n");

	if( !me->query("group"))
		return notify_fail("�㻹û�н������ţ����Ƚ���һ����˵�ɡ�\n");
          if( userp(me) && (int) me->query("grouptitle")!= 1)
             	   return notify_fail("���������ų��������ˣ�\n");
            if(userp(me) && (me->query("grouplv")*5 < (int)me->query("groups")) )
		return notify_fail("��������Ŀǰ�ĵȼ�������������Ա�Ѿ��ﵽ���ޡ�\n");
      
	if( (object)ob->query_temp("pending/join") == me )
	 {
	    ob->set("groupscore", 0);
	    ob->set("group",me->query("group"));
	    ob->set("grouptitle",10);
	    ob->set("grouplv",me->query("grouplv"));
	  c_name = me->query("group");
                    me->add("groups",1);
	    message_vision("$Nͬ��$n����"+me->query("group")+"��\n\n",me, ob);
          ob->delete_temp("pending/join");
	    me->delete_temp("pending/invite");
	    ob->delete_temp("pending/join");
	    tell_object( ob, sprintf("��ϲ����Ϊ%s����Ա��\n", ob->query("group")));
		file = "/data/group/"+c_name;
		temp = ob->query("name");
       		write_file(file, "\n"+ temp);
          return 1;
	}
	 else
	 {
		old_rec = me->query_temp("pending/invite");
		if( ob==old_rec )
			return notify_fail("��������" + ob->name() + "�����Լ������ţ����ǶԷ���û�д�Ӧ��\n");
		else if( objectp(old_rec) ) {
			write("��ı����ⲻ������" + old_rec->name() + "���������ˡ�\n");
			tell_object(old_rec, me->name() + "�ı����ⲻ���������������ˡ�\n");
		}

		me->set_temp("pending/invite", ob );
		message_vision("\n$N����$n�������š�\n", me, ob);
		tell_object(ob, YEL "�����Ը�����" + me->name() + "������"+me->query("group")+"������ join ָ�\n" NOR);
		return 1;
	}
}


int help(object me)
{
        write(@HELP
ָ���ʽ : invite [cancel]|<����>
 
���ָ������������Է������Լ������š�
 
HELP
        );
        return 1;
}
