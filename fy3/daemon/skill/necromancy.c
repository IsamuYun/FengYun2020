// necromancy.c

inherit SKILL;

int valid_enable(string usage) 
{ 
        return usage=="spells" ;

}

int valid_learn(object me)
{
	if( (int)me->query_skill("taoism",1) < (int)me->query_skill("necromancy",1))
		return notify_fail("你的天师正道修为不够，无法领悟更高深的三清道术。\n");
	return 1;
	if (me->query("level")<40)
		return notify_fail("你的等级还不足四十级。\n");
}

string cast_spell_file(string spell)
{
	return CLASS_D("sanqing") + "/necromancy/" + spell;
}
int practice_skill(object me)
{
        return notify_fail("三清道术只能通过向师傅学习来提升。\n");

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

