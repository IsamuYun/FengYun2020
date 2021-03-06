// celestrike.c

inherit SKILL;

mapping *action = ({
        ([      "action":               "$N双手搭向$n，身体向后倾斜，似乎要将$n摔倒",
                "parry":                30,
                "damage":                50,
                "dodge":                10,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N抱住$n的$l，将$n举过头顶，往地下狠狠一摔",
                "parry":                30,
                "damage":                50,
                "dodge":                10,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N双手前伸，似乎要抓住$n的$l",
                "parry":                10,
                "damage":                50,
                "dodge":                30,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N冷不盯伸出左脚，企图将$n拌倒在地下",
                "parry":                10,
                "damage":                80,
                "dodge":                30,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N右脚凌空，晃出一片腿影，霎那间向$n的$l一连踹出三脚",
                "parry":                30,
                "damage":                70,
                "dodge":                10,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练虎掌必须空手。\n");
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
        "$n就势一滚，双手一撑地，全身弹出$N的$w的攻击范围。\n",
});

string *unarmed_parry_msg = ({
        "$n就势一滚，双手一撑地，全身弹出$N的攻击范围。\n",
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

