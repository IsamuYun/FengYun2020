//ħ���
#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me) { 
  if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("����Ŀǰ��״������û���ʸ���ħ�����\n");

return 1; }
int practice_skill(object me)
{
        return 
notify_fail("ħ���ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("zhuge") + "/moshen-force/" + func;
}
int effective_level() { return 20;}
int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 30;
}

