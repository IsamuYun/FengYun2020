// celestrike.c

inherit SKILL;

mapping *action = ({
        ([      "action":               "$N左掌护胸，右拳凝劲后发，一式「铁索拦江」，缓缓推向$n的$l",
                "parry":                20,
                "force":                30,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N使一式「云断秦岭」，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
                "parry":                20,
                "force":                30,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N合掌抱球，猛吸一口气，一式「怀中抱月」，双掌疾推向$n的肩头",
                "parry":                50,
                "force":                30,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N左掌划一半圆，一式「长虹贯日」，右掌斜穿而出，疾拍$n的胸前大穴",
                "parry":                30,
                "force":                30,
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
        "$n怪叫一声，以硬碰硬把$N震开五步。\n",
});

string *unarmed_parry_msg = ({
        "$n左手虚晃，右手早对$N的要害伏下数个后招。\n",
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
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

