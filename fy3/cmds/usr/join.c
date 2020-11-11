// join.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_app;
	int i;
	string *skname,file,temp,c_name;

	if( !arg ) return notify_fail("ָ���ʽ��join [cancel]|<����>\n");

	if( me->query("group") ) 
		return notify_fail("����������֮ǰ�����������Ŀǰ�������ų������˳���\n");
            
	if( arg=="cancel" ) {
		old_app = me->query_temp("pending/join");
		if( !objectp(old_app) )
			return notify_fail("�����ڲ�û�м����κ����ŵ���˼��\n");
		write("��ı����ⲻ�����" + old_app->name() + "�������ˡ�\n");
		tell_object(old_app, me->name() + "�ı����ⲻ�������������ˡ�\n");
		me->delete_temp("pending/join");
		return 1;
	}

	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("�������˭�����ţ�\n");

	if( ob==me ) return notify_fail("�㵽���벻��������Ű������˷�ʱ�䡣\n");

	if( ! ob->query("group") ) 
		return notify_fail(ob->name() + "û���Լ������š�\n");	
	if(  ob->query("grouptitle") != 1 )
		return notify_fail(ob->name() + "���������ų���\n");

	if( (object)ob->query_temp("pending/invite") == me ) 
	{
		message_vision("$N��������$n������"+ob->query("group")+"����\n\n",me, ob);
		me->set("groupscore", 0);
	      me->set("group",ob->query("group"));
	      me->set("grouptitle",10);
	      me->set("grouplv",ob->query("grouplv"));
	   c_name = ob->query("group");
                      ob->delete_temp("pending/invite");
		tell_object(ob, "��ϲ��������ţ�\n");
		file = "/data/group/"+c_name;
		temp = me->query("name");
       		write_file(file,"\n"+ temp);

		return 1;
	} 
	else
	 {
		old_app = me->query_temp("pending/join");
		if( ob==old_app )
			return notify_fail("�������" + ob->name() + "�����ţ����ǶԷ���û�д�Ӧ��\n");
		else if( objectp(old_app) )
		 {
			write("��ı����ⲻ�����" + old_app->name() + "�������ˡ�\n");
			tell_object(old_app, me->name() + "�ı����ⲻ�������������ˡ�\n");
		}

		message_vision("$N��Ҫ����$n�����š�\n", me, ob);
		me->set_temp("pending/join", ob );
		if( userp(ob) ) {
			tell_object(ob, YEL "���������" + me->name() + "�������ţ��� invite ָ�\n" NOR);
			return 1;
		}
	}
}


int help(object me)
{
        write(@HELP
ָ���ʽ : join [cancel]|<����>
 
���ָ�����������Է������š�
 
HELP
        );
        return 1;
}
