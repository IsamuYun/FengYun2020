// 幽灵剑法 written by tiandi。 

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N在两片剑光中，宛然一对银翅的红蜻蜓，飞、飘、点、落，轻妙无尽",
                "dodge":                -120,
                "damage":               130,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"剑如银翼，霎时一变，随即如斜飞一般，已到了地上，剑光又卷住了$n",
                "dodge":                -20,
                "damage":               130,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$w精厉的光芒，一刹那问盖过了$n双目的凌厉",
                "dodge":                -130,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一挥剑，明明刺出千百道剑花，却只刺出一剑。",
                "dodge":                -140,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N再一扬剑，明明刺出一剑，却有千百道剑花",
                "dodge":                -140,
                "damage_type":  "刺伤"
        ]),
 
});

int valid_learn(object me)
{
        object ob;
	if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("以你目前的状况，还没有资格练幽灵剑法。\n");

	 if( (int)me->query_skill("youling-force",1) < 100 )
                return notify_fail("你的内力不够，没有办法练幽灵剑法。\n");
	 
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("剑呢？\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习幽灵剑。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍流星幽灵剑。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("zhuge") + "/youling-sword/" + action;
}
 
int effective_level() { return 18;}

string *parry_msg = ({
        "$n挪，移，闪，避，躲开了$N的$w！\n",
        "$n使出一招「千变万幻」，手中的$v化做漫天残照，荡开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
       "$n突然倒后而飞，白衣遮住了太阳，成了黑的物体。\n",
        "只见眼前人影一闪，白衣倏飘，$n已窜向$N。\n",

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
	return -10;
}
int black_white_ness()
{
	return 15;
}

