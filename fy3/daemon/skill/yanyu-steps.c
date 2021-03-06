
inherit SKILL;

string *dodge_msg = ({
	"$n一招「燕飞南天」轻轻巧巧地避了开去。\n",
        "$n身形往上一拔，一招「天外飞仙」，一个转折落在数尺之外。\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") ;
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练燕鱼步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练雁歌步法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 19;}

int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("yihua") + "/yanyu-steps/" + action;
}

