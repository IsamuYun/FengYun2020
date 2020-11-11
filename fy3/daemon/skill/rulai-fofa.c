// by xgchen@zzfy
inherit SKILL;

int valid_enable(string usage) { return usage=="chanting"; }

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("你的杀气太重，无法修炼如来佛法。\n");
        if(me->query("family/family_name") != "少林寺")
                return notify_fail("你不是少林和尚，无法修炼如来佛法。\n");
return 1;
}
int practice_skill(object me)
{
        return 
notify_fail("如来佛法不能练习。\n");
}
string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/rulai-fofa/" + action;
}
int effective_level() 
{ return 20;}

int learn_bonus()
{
     return -3000;
}
int practice_bonus()
{
        return -5000;
}
int black_white_ness()
{
        return 400;
}

