// TIE@FY3
inherit SKILL;
int valid_enable(string usage) { return usage=="magic"; }
int valid_learn(object me)
{
	if( (int)me->query_skill("putiforce",1) < 10
	||	(int)me->query_skill("putiforce",1) <= (int)me->query_skill("qiankunwuxing",1) )
		return notify_fail("����е��ķ�����������޷�ѧϰǬ�����Ρ�\n");
	return 1;
}

string conjure_magic_file(string spell)
{
	return CLASS_D("lishi") + "/qiankunwuxing/" + spell;
}
int effective_level() { return 10;}
int learn_bonus()
{
	return -10;
}
int practice_bonus()
{
	return -5;
}
int black_white_ness()
{
	return 10;
}
int practice_skill(object me)
{
	return notify_fail("Ǭ������ֻ����ѧ��\n");
}
