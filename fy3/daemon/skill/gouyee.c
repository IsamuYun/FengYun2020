// gouyee.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if( (int)me->query("max_mana") < (int)me->query_skill("gouyee") * 5 )
                return 
notify_fail("���ħ���������޷����������ķ������衣\n");

        return 1;
}

int practice_skill(object me)
{
        return 
notify_fail("�����ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("sanqing") + "/gouyee/" + func;
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return -30;
}
string belong()
{
	return "sanqing";
}
 
