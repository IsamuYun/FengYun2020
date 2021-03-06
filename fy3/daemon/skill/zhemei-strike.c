inherit SKILL;
mapping *action = ({
        ([      "action":               "$N使一招「墙角数支梅」，对准$n的$l连出数指",
                "force":                300,
                "parry":                200,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N右掌呈拈花指状，一招「凌寒独自开」便往$n的$l招呼过去",
                "force":                400,
                "parry":                100,
                "damage_type":  "瘀伤"
        ]),
        
});
int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练天山折梅手必须空手。\n");
        return 1;
}
int valid_enable(string usage)
{
        return usage=="unarmed";
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        if( (int)me->query("kee") < 90 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 90);
        return 1;
}
int effective_level() { return 22;}
string *parry_msg = ({
        "$n以守为攻，一招「遥知不是雪」，猛击$N握$w的手腕。\n",
});
string *unarmed_parry_msg = ({
        "$n左掌后撤，右掌自保，一招「为有暗香来」，将$N封于尺外。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int learn_bonus()
{
        return -300;
}
int practice_bonus()
{
        return -300;
}
int black_white_ness()
{
        return 60;
}

