
inherit SKILL;

int valid_enable(string usage) 
{ 
    return (usage=="magic")
        || (usage=="force");
}

int valid_learn(object me)
{
    int lvl = me->query_skill("moon-magic", 1);
    if( ((int)me->query_skill("spells", 1) <= lvl)
     	|| ((int)me->query_skill("magic", 1) <= lvl)
     	|| ((int)me->query_skill("force", 1) <= lvl)
    	)
    {
    	return notify_fail("你的法术、咒术或内功修为还不够高深，无法领悟更高深的水月仙法。\n");
	}

	if( me->query("family/master_name") != "赵灵儿")
		return notify_fail("只有水月宫弟子可以修习水月仙法。\n");

    if(lvl>=120 && me->query("gender")!="女性")
        return notify_fail("你阴阳不合，除非练就一样至阴的内功，否则无法领悟更高深的水月仙法。\n");
    return 1;
}

int effective_level() { return 23;}

string conjure_magic_file(string spell)
{
    return CLASS_D("xianlingdao") + "/moon-magic/" + spell;
}

string exert_function_file(string func)
{
    return CLASS_D("xianlingdao") + "/moon-magic/" + func;
}
 
int learn_bonus()
{
        return -5300;
}

int practice_bonus()
{
        return -5300;
}

int black_white_ness()
{
        return 100;
}
