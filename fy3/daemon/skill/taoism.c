// taoism.c

inherit SKILL;

void create() { seteuid(getuid()); }

int valid_enable(string usage) { return usage=="literate"; }

string type() { return "knowledge"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("scratching",1) < (int)me->query_skill("taoism",1))
		return notify_fail("��ķ�֮����Ϊ�������޷�������������ʦ������\n");
	return 1;
}

int practice_skill(object me)
{       
        return notify_fail("�����༼�ܱ�����ѧ�Ļ��Ǵ�ʵս�л�ȡ���顣\n");
}
int effective_level() { return 5;}

int learn_bonus()
{
	return -50;
}
int practice_bonus()
{
	return -25;
}
int black_white_ness()
{
	return 30;
}
string belong()
{
	return "sanqing";
}
