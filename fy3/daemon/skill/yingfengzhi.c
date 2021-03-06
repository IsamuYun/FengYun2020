// wenxin@FYtx
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N身形旋转如飞，一招「影随风动」，蓦地斜出一指，点向$n$l",
                "dodge":                -30,
                "parry":                30,
                "force":                80,
                "damage_type":  "刺伤",
                "weapon":               "左手食指",
        ]),
        ([      "action":               
"$N力透指尖，一招「捕风捉影」，一直向$n的$l戳去",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺伤",
                "weapon":               "右手食指",
        ]),
        ([      "action":               

"$N一招「泼风急出」，急出数指，指风破空，往$n的$l点去",
                "dodge":                -30,
                "parry":                30,
                "force":                140,
                "damage_type":  "刺伤",
                "weapon":               "一缕指风",
        ]),
        ([      "action":               
"只见$N进身跟步，一招「幻影附行」，连出数指，指指不离往$n的$l",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺伤",
                "weapon":               "右手中指",
        ]),
});

int valid_learn(object me)
{
//        if( (string)me->query("gender") != "男性" )

//                return notify_fail("指是只有男子才能练的武功。\n");
        if((int)me->query("max_force") < 200 )
                return notify_fail("你的内力修为不够！\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练影风指必须空手。\n");
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

        if( (int)me->query("sen") < 30 )
                return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的内力不够了。\n");

        me->receive_damage("sen", 30);
        me->add("force", -10);

        return 1;
}
 
int effective_level() { return 20;}

string *parry_msg = ({
        "$n一招「幻影附行」，急出一指，指风悄无声息的点歪了$N的$w。\n",
        "$n神色悠闲，一招「影影绰绰」，倏地一指递出，点向$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n并起二指，一鹤冲天，一招「风随影出」，戳向$N的周身大穴。\n",

        "$n身形蓦地消逝，一招「影风忽住」，一指解围。\n",
        "$n化出无数身影，一招「影影绰绰」身身皆出一指，一齐点向$N。\n",
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
        return -100;
}
int practice_bonus()
{
        return -100;
}

int black_white_ness()
{
        return 50;
}

string perform_action_file(string action)
{
        return CLASS_D("lou") + "/unarmed/" + action;
}