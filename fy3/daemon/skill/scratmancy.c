
inherit SKILL;

int valid_enable(string usage) 
{ 
        return usage=="scratching";

}

int valid_learn(object me)
{
	if( (int)me->query_skill("taoism",1) < (int)me->query_skill("scratmancy",1))
		return notify_fail("�����ʦ������Ϊ�������޷��������������������\n");
	return 1;
}
int practice_skill(object me)
{
        return 
notify_fail("�㲻������ô�ɡ�\n");

}

string scribe_spell_file(string spell)
{
	return CLASS_D("sanqing") + "/scratmancy/" + spell;
}


int effective_level() { return 15;}

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
