// necromancy.c

inherit SKILL;

int valid_enable(string usage) 
{ 
        return usage=="spells" ;

}

int valid_learn(object me)
{
	if( (int)me->query_skill("taoism",1) < (int)me->query_skill("necromancy",1))
		return notify_fail("�����ʦ������Ϊ�������޷��������������������\n");
	return 1;
	if (me->query("level")<40)
		return notify_fail("��ĵȼ���������ʮ����\n");
}

string cast_spell_file(string spell)
{
	return CLASS_D("sanqing") + "/necromancy/" + spell;
}
int practice_skill(object me)
{
        return notify_fail("�������ֻ��ͨ����ʦ��ѧϰ��������\n");

}
int effective_level() { return 25;}

int learn_bonus()
{
	return 30;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return -50;
}
string belong()
{
	return "sanqing";
}

