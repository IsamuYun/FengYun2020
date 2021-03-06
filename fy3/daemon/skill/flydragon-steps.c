inherit SKILL;

string *dodge_msg = ({
        "但是$n身形飘忽，一招「龙飞凤舞」拔地而起，避开这致命一击。\n",
        "$n身随意转，一式「龙腾虎跃」，全身化作无数虚影掠出丈外。\n",
        "$n身形往上一拔，一招「游龙在天」，腾空而起，避了开去。\n",
        "$n气聚丹田，一招「龙蟠虎踞」，身形急缩，躲开$N那致命一击。\n",
        "$n身影微动，已经藉一招「卧龙出渊」轻轻闪过。\n",
        "$n腾空一跃，双脚向前一踢，一招「蛟龙出海」，躲开数尺。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        return 1;
}


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力太差了，不能练飞龙步法。\n");
        me->receive_damage("kee", 30);
        return 1;
}
int effective_level() { return 15;}

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
        return 20;
} 
string perform_action_file(string action)
{
        return CLASS_D("moondoor") + "/flydragon-steps/" + action;
}
