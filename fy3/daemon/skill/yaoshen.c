// yaoshen.c

inherit SKILL;
int valid_enable(string usage) 
{ 
        return usage=="spells" ;

}
int valid_learn(object me)
{
	if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") || me->query_skill("youling-sword",1)<150) 
    		return notify_fail("以你目前的状况，还没有资格练妖神。\n");

return 1;
}

string cast_spell_file(string spell)
{
	return CLASS_D("zhuge") + "/yaoshen/" + spell;
}
int practice_skill(object me)
{
        return notify_fail("妖神只能用学的\n");
}

int effective_level()
 { return 17;}

int learn_bonus(){
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

