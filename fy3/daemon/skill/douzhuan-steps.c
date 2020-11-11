inherit SKILL;
string *dodge_msg = ({
        "$n一招「星罗棋布」轻轻巧巧地避了开去。\n",
        "只见$n身影一晃，一式「流星似电」早已避在七尺之外。\n",
        "$n使出「倒转天权」，轻轻松松地闪过。\n",
        "$n左足一点，一招「天马行空」腾空而起，避了开去。\n",
        "可是$n使一招「八面玲珑」，身子轻轻飘了开去。\n",
        "但是$n一招「风云变幻」使出，早已绕到$N身後！\n"
});
int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练斗转星移步法。\n");
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
                return notify_fail("你的气或内力不够，不能练斗转星移步法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
int effective_level() { return 10;}
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
        return CLASS_D("bloomdoor") + "/douzhuan-steps/" + action;
}
