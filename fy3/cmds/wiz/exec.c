// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("ָ���ʽ: smash <living>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("�Ҳ��������ҡ�\n");
	message_vision("$N˫��һ�٣�һ�����׽�$n��Ϊ�ɻң���\n",me,ob);
	ob -> save();
        BAN_D->dynamic_add(query_ip_number(ob));
	seteuid(ROOT_UID);
	destruct(ob);
	return 1;
}
 
int help(object me)
{
   write(@HELP
ָ���ʽ: exec <���>
��ĳ������߳����� 
������IP��ʱBAN��
����������REBOOT�����IP�ſ���������

also see ban
HELP
   );
   return 1;
}
