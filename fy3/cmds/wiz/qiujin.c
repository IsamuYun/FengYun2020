// edit by xgchen@fy
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	object room;
	if (!arg) return notify_fail("ָ���ʽ: imprison <player>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("�Ҳ��������ҡ�\n");
	message_vision("$N��һ�ӣ�һ��΢�罫$n������Ƽ���������\n",me,ob);
	if(!room =find_object("/d/wiz/jail"))
	room = load_object("/d/wiz/jail");
	ob->move(room);
	ob -> save();
	return 1;
}
 
int help(object me)
{
   write(@HELP
ָ���ʽ: imprison <���>
��ĳ����ҽ����ڷ��Ƶ��᷸�����
HELP
   );
   return 1;
}
