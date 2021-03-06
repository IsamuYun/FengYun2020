inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N使出一招「天诛地灭」，单掌轻挥，一道浑厚内力打向$n的$l",
                "dodge":                100,
                "parry":                100,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「日暮穷途」，化出一道幻影，抡掌拍向向$n的$l",
                "dodge":               100,
                "parry":                100,
                "force":                 70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出化神掌法中的「气贯长虹」，气走周天，一掌拍向$n的$l",
                "dodge":               100,
                "parry":                100,

                "force":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形急进，化出道道身影，使出「气吞山河」，身影突然合为一体，双掌已到了$n的眼前",
                "dodge":                100,
                "parry":                100,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双臂一振，内力无形而出，一招「汹涌澎湃」击向$n$l",
                "dodge":                100,
                "parry":                100,
                "force":                140,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌晃动，东一引西一划，使出「风卷残云」，掌风暗带巨大旋力，从空中当头向$n的$l出掌攻击",
                "dodge":                200,

                "parry":                200,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练化神掌法必须空手。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}


int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n双掌一分，使出一招「东窗事发」，「啪」的一声将$N的$w夹在双掌之间。\n",
        "$n略一转身，一招「以逸待劳」拍向$N拿着$w的手。\n",
        "$n使出「画地为牢」，吐气开声，双掌一划，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n凝神定气，一招「以毒攻毒」虚空拍出三掌，逼得$N撤招自保。\n",

        "$n施展出「扑朔迷离」，轻描淡写的化解了$N的攻势。\n",
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
        return 10;
}
int practice_bonus()
{
        return 5;
}
int black_white_ness()

{
        return 10;
}

string perform_action_file(string action)
{
        return CLASS_D("moondoor") + "/huashen-strike/" + action;
}