// force.c

#include <ansi.h>

inherit SKILL;

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
        return "/d/force/" + func;
}


int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 100;
}
int effective_level() { return 5;}
string belong()
{
	return "common";
}