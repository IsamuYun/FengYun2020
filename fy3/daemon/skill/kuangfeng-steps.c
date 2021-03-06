inherit SKILL;

string *dodge_msg = ({
        "$n一招「风起云涌」，步法轻灵，身形飘动，躲开了$N招式。\n",
        "只见$n凝神不动，等$N的招式用老，一式「微风拂面」，轻巧地躲在一旁。\n",
        "$n使出「乌云翻滚」,轻轻避开。\n",
        "$n双足一点，一招「风卷残云」腾空而起，避了开去。\n",
        "可是$n使一招「八面来风」，步法飘忽不定，$N的攻击失去了准头。\n",
        "$n经藉一招「狂风怒号」，身形飘退，轻轻闪过。\n",
        "但是$n一招「带卷神州」使出，身形晃动，幻出数道身影，人已跑出几丈！\n",

});

int valid_enable(string usage)
{
        return (usage=="dodge") ;
}

int valid_learn(object me)
{

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法狂风机步。\n");

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
                return notify_fail("你的气或内力不够，不能练狂风步法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

int effective_level() { return 25;}

int learn_bonus()
{
        return -90;
}
int practice_bonus()
{
        return -50;
}
int black_white_ness()
{
        return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("lou") + "/steps/" + action;
}