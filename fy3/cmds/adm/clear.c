#pragma save_binary
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *npc;
	int i;
	string msg;
	msg="ϵͳ���������������ҿ��ܻ�ͣ��Ƭ�̡���ԭ�¡�\n";
	message("vision",HIC+msg+NOR,users());
        npc=livings();
for(i=0;i<sizeof(npc);i++)
	{
	if(userp(npc[i])) continue;
//        if(environment(npc[i])) continue;
	destruct(npc[i]);
	}
	msg="�����ϡ�\n";
	message("vision",HIC+msg+NOR,users());
	return 1;
}
