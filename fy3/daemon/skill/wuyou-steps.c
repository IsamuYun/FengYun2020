// wuyou-steps.c

inherit SKILL;

string *dodge_msg = ({
        "$n身行不定，一招「落英缤纷」轻轻巧巧地弹了开去。\n",
        "只见$n身影一晃，一式「飞花落叶」早已避在数丈之外。\n",
        "$n使出「夕阳朝露」，轻轻松松地闪身躲过。\n",
        "$n左足微点，一势「落花无意」腾空而起，避了开去。\n",
        "可是$n使一招「弱柳扶风」，身子轻轻飘了开去。\n",
        "$n身影微动，已经藉一招「踏露观雾」轻轻闪过。\n",
        "但是$n一招「山花烂漫」使出，早已绕到$N身後！\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)

{
        if( (int)me->query("max_force") < 25 )
                return notify_fail("你的内力不够，没有办法练无忧步法。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的气或内力不够，不能练习无忧步法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;

}
int effective_level() { return 20;}

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
        return 10;
}

string perform_action_file(string action)
{
        return CLASS_D("baihua") + "/step/" + action;
}