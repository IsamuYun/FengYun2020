// kongming.c

inherit SKILL;

mapping *action = ({
    ([  "action":       "$N使一招「空屋住人」，双手轻飘飘地箍向$n$l",
        "dodge": 130,
        "parry": 120,
        "force": 180,
        "damage_type": "瘀伤"
        ]),
    ([  "action":       "$N左掌一平,右掌一伸,一招「空碗盛饭」直拍$n的$l",
        "dodge": -120,
        "parry": 120,
        "force": 320,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N身形绕$n一转，双手上撩,一招「空钵装水」击向$n$l",
        "dodge":  125,
        "parry":  120,
        "force": 260,
        "damage_type": "瘀伤"
        ]),
    ([  "action":       "$N左掌一按,右掌一挥,一招「虚怀若谷」拍向$n的$l",
        "dodge": -120,
        "parry":  0,
        "force": 400,
        "damage_type": "瘀伤"
        ]),
    ([  "action":       "$N使一招「空山鸟语」，$n的$l已围在$N的重重掌影之下",
        "dodge": -120,
        "parry":  110,
        "force": 540,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N神色一敛，使出「我心空明」，围绕$n的$l接连出掌",
        "dodge":  140,
        "force": 600,
        "damage_type": "瘀伤"
    ]),
});

int valid_enable(string usage) { return usage=="unarmed"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练空明拳必须空手。\n");
        if ((int)me->query("max_force") < 100)
        return notify_fail("你的内力太弱，无法练空明拳。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 40)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 10)
        return notify_fail("你的内力不够了！休息一下再练吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

int effective_level() { return 30;}

int learn_bonus()
{
        return -220;
}

int practice_bonus()
{
        return -220;
}

int black_white_ness()
{
        return 50;
 }

string perform_action_file(string action)
{
        return CLASS_D("linjiabao") + "/kongming-quan/" + action;
}
