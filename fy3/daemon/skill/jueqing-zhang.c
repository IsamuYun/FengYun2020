inherit SKILL;
mapping *action = ({
([      "action" : "$N双掌交错,一招「无情」，左掌虚探，右掌聚力拍向$n的头部",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
([      "action" : "$N凝神聚气，一招「无意」，掌风如细雨般向$n的$l扫去",
                "dodge":                10,
                "parry":                30,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
([      "action" : "$N一招「无泪」，双掌幻化为一片花影，将$n笼罩于花影之内。",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "瘀伤"
        ]),
([      "action" : "$N身形凌空飞起，一招「无痕」，向$n的$l连击数掌",
                "dodge":                10,
                "parry":                30,
                "damage":                70,
                "damage_type":  "瘀伤"
        ]),
([      "action" : "$N内气上提，一招「无命」，只见双掌灌满劲力斜斜攻向$n",
                "dodge":                20,
                "parry":                30,
                "damage":                60,
                "damage_type":  "瘀伤"
        ]),
});

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int valid_learn(object me)
{
    if ( me->query("gender") != "女性")
       return notify_fail("绝情掌从无男子练习!\n");
        if ((int)me->query("max_force") < 500)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("mingyu-shengong", 1) < 150)
                return notify_fail("你的明玉神功火候太浅。\n");
        return 1;
}
int effective_level() { return 25;}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
int practice_skill(object me)
{
        if ((int)me->query_skill("mingyu-shengong", 1) < 250)
                return notify_fail("你的明玉神功火候太浅。\n");
        if ((int)me->query("kee") < 300)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 400)
                return notify_fail("你的内力不够练绝情掌。\n");
        me->receive_damage("kee", 300);
        me->add("force", -100);
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("yihua") + "/jueqing-zhang/" + action;
}
int learn_bonus()
{
        return 300;
}
int practice_bonus()
{
        return -300;
}
int black_white_ness()
{
        return 820;
}

