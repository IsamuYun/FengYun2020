// petfangyu.c

#include <ansi.h>

inherit SKILL;
int valid_learn(object me)
{
        object ob;
	if ( me->query("is_pet") != 1)
		return notify_fail("这技能只有宠物能学习。\n");

        return 1;
}

int learn_bonus()
{
	return 5;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

int effective_level() { return 5;}
string belong()
{
	return "pet";
}