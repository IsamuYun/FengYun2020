// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }



int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

int effective_level() { return 10;}
string belong()
{
	return "official";
}