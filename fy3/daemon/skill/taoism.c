// taoism.c

inherit SKILL;

void create() { seteuid(getuid()); }

int valid_enable(string usage) { return usage=="literate"; }

string type() { return "knowledge"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("scratching",1) < (int)me->query_skill("taoism",1))
		return notify_fail("你的符之术修为不够，无法领悟更高深的天师正道。\n");
	return 1;
}

int practice_skill(object me)
{       
        return notify_fail("法术类技能必须用学的或是从实战中获取经验。\n");
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
