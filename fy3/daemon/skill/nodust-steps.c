// notracesnow.c

inherit SKILL;

string *dodge_msg = ({
        "$n一招「轻烟缥缈」轻轻巧巧地避了开去。\n",
        "只见$n身影一晃，一式「青云直上」早已避在七尺之外。\n",
        "$n使出「凌空飞渡」，轻轻松松地闪过。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力不够，没有办法练无尘步法。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
   return notify_fail("无尘步法只能通过向师傅学习来提升。\n");
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 20;
}
string perform_action_file(string action)
{
        return CLASS_D("tianchui") + "/nodust-steps/" + action;
}
string belong()
{
	return "tianchui";
}

