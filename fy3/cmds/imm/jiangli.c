// jiangli.c by tiandi

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
	object obj,gift;
	string msg,name;
	
	if( !arg ) return notify_fail("��Ҫ��˭������\n");

	if(!arg || sscanf(arg,"%s %s",name,msg) != 2)
                     return notify_fail("��������ȷ�ĸ�ʽ��jiangli <id> <reason>��\n");

	obj = find_player(name);
	if(!obj)		return notify_fail("�����û�����ߡ�\n");
		
	gift = new("/d/wiz/tiandi/obj/jiangli");
	gift ->move(obj);
	
 	message("system",HIC "\n�����ַ��ơ�������Ϣ��"+obj->query("name")+"("+ name + ")����["HIR+msg+HIC"]������ͻ����"+this_player()->query("name")+"����������Ʒһ����\n" NOR,users());

	message_vision(HIY"����ͻȻ����ʲô������ֱ������$N�Ŀڴ���\n"NOR, obj);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : jiangli <id> <reason>
 
���ָ��Ὣ����ʦ���Ÿ��Ա�վ�������׵���ҵ�һ����Ʒ��
 
HELP
    );
    return 1;
}