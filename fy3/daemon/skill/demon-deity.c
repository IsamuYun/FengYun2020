// yiru@hero
// 魔神步

inherit SKILL;

string *dodge_msg = ({
        "$n不退反进，向前踏出一步，逼得$N中途撤招。\n",
        "$n左跨一步，右跨一步，一时间身影似乎变成了三个，把$N晃得眼花缭乱。\n",
        "$n身体后仰，一个「铁板桥」，闪开了$N这一招。\n",
        "$n脚步一错，一旋身闪到了$N的背后。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 180 )
                return notify_fail("你的内力不够，没有办法练魔神步法。\n");

        return 1;
}

int effective_level() { return 12;}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("max_force") < 2 )
        return notify_fail("你的内力不够，不能练魔神步法。\n");
    me->add("max_force", -2);
    me->set("force", me->query("max_force"));
    return 1;
}

int learn_bonus()
{
        return -520;
}

int practice_bonus()
{
        return -520;
}

int black_white_ness()
{
        return -18;
}

string perform_action_file(string action)
{
    return CLASS_D("heimiao") + "/demon-deity/" + action;
}
