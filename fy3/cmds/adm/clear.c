#pragma save_binary
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *npc;
	int i;
	string msg;
	msg="系统清除程序启动，大家可能会停滞片刻。请原谅。\n";
	message("vision",HIC+msg+NOR,users());
        npc=livings();
for(i=0;i<sizeof(npc);i++)
	{
	if(userp(npc[i])) continue;
//        if(environment(npc[i])) continue;
	destruct(npc[i]);
	}
	msg="清除完毕。\n";
	message("vision",HIC+msg+NOR,users());
	return 1;
}
