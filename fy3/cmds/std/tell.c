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
                return notify_fail("���Ƶ�������ˣ�\n");
	if((int)me->query("mud_age") < NEW_PERIOD)
		return notify_fail("��ֻ����ʹ�ã�say����\n");
	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}
	obj = find_player(target);
        if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
        if(obj->query_temp("block_msg/all")==1) return notify_fail("������Ѿ�ʧȥ֪���������Խ���TELL����Ϣ��\n");
        if(obj->query_temp("block_msg/all")==1) return notify_fail("����˶�����,�����Խ���TELL����Ϣ��\n");
	name = (string) me->query("id");
	refuse_name = (string) obj->query("env/no_tell");
	if( !wizardp(me) && (refuse_name == "all" || refuse_name == name))
	return notify_fail("�����ѹر��ˣԣţ̣�Ƶ����\n");
	    if (query_idle(obj)>180) write(YEL+obj->name(1)+"�Ѿ�����"+query_idle(obj)/60+"���ӣ������������ϻش���Ӵ��\n"+NOR);
   if (in_edit(obj)) return notify_fail("���ǣ��Է��������ڱ༭������\n");
write(GRN "�����" + obj->name(1) + "��" + msg + "\n" NOR);
	tell_object(obj, sprintf( HIG "%s�����㣺%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)�����㣺%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s �����㣺%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

����������ָ��������ط���ʹ����˵����

�������ָ�reply
HELP
	);
	return 1;
}
