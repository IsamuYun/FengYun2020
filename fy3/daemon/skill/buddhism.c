// buddhism.c

inherit SKILL;

int valid_enable(string usage) { return usage=="literate"; }

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("���ɱ��̫�أ��޷�������˷𷨡�\n");
	return 1;
}
int effective_level() 
{ return 20;}

int learn_bonus()
{
	return -30;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 40;
}
string belong()
{
	return "common";
}

