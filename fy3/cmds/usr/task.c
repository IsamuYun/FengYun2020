// by Tie@fy3 hehe
#include <ansi.h>
int main(object me, string str)
{
	string output;
        me->add("sen",-5);
	output = HIR"��  ���Ƣ�ʹ����\n" NOR;
	output += "������������������������������������������������������\n";
	output += TASK_D->dyn_quest_list();
	output += "������������������������������������������������������\n\n";

	me->start_more(output);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: tasks

���ָ����������֪Ŀǰ������ʹ��.

HELP
	);
	return 1;
}
