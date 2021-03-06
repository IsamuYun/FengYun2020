// celestrike.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N一式「白云出岫」，双掌间升起一团淡淡的白雾，缓缓推向$n的$l",
                "dodge":                -30,
                "parry":                10,
                "force":                200,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
	"$N并指如剑，一式「白虹贯日」，疾向$n的$l戳去",
                "dodge":                -10,
                "parry":                -30,
                "force":                170,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使一式「云断秦岭」，左掌微拂，右掌乍伸乍合，猛地插往$n的$l",
                "dodge":                -30,
                "parry":                10,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌隐隐泛出青气，一式「青松翠翠」，幻成漫天碧绿的松针，雨点般向$n击去",
                "dodge":                10,
                "parry":                -30,
                "force":                260,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形往上一纵，使出一式「天绅倒悬」，双掌并拢，笔直地向$n的$l插去",
                "dodge":                -20,
                "parry":                -30,
                "force":                240,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形一变，使一式「无边落木」，双掌带着萧刹的劲气，猛地击往$n的$l",
                "dodge":                -70,
                "parry":                -10,
                "force":                280,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使一式「高山流水」，左掌凝重，右掌轻盈，同时向$n的$l击去",
                "parry":                -40,
                "force":                320,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练混元掌法必须空手。\n");
        if( (int)me->query_skill("xizia-shengong", 1) < 20 )
                return 
notify_fail("你的紫霞神功火候不足，无法练天邪掌法。\n");
        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力太弱，无法练混元掌法。\n");
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
        "$n化掌为刀，一招「碧血五指挑」急切$N拿着$w的手。\n",
        "$n双掌交错，使出一招「童子拜寿」，「啪」的一声将$N的$w夹在双掌之间。\n",
        "$n略一转身，一招「兵出无名」拍向$N拿着$w的手。\n",
        "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n步走七星，一招「反客为主」虚空拍出十三掌，逼得$N撤招自保。\n",
        "$n化掌为指，一招「掌指双飞」反点$N的周身要穴。\n",
        "$n施展出「掌指双飞」，轻描淡写的化解了$N的攻势。\n",
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
	return -10;
}
string perform_action_file(string action)
{
	 return CLASS_D("huashan") + "/hunyuan-zhang/" + action;
}

