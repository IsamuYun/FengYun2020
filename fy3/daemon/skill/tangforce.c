// tangforce.c 唐诵
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("唐诵只能从实践中来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("tangmen") + "/tangforce/" + func;
}
 
int effective_level() { return 10;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 20;
}



