// 更改于2002-2-1 xgchen2fy
#include <ansi.h>
int main(object me, string str)
{
	string output;
        me->add("sen",-5);
        output = HIR"使命榜\n" NOR;
	output += "———————————————————————————\n";
	output += TASK_D->dyn_quest_list();
	output += "———————————————————————————\n\n";
        output +=HIR"目前共有使命八十二个，其中包含有十个特殊的使命。\n " NOR;    
	me->start_more(output);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: tasks

这个指令是用来得知目前的所有使命.

HELP
	);
	return 1;
}
