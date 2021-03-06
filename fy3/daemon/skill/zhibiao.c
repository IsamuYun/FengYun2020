// fonxansword.c

inherit SKILL;

mapping *action = ({
([	"action" : "$N侧身抬臂，右指划了个半圈，一式「指花落砚」击向$n的$l",
	"force" : 60,
        "dodge" : -5,
	"lvl" : 0,
	"damage": 10,
		"damage_type" : "刺伤"
]),
([	"action" : "$N左掌虚托，一式「五梅吐蕊」，右指穿腋疾出，指向$n的胸前",
	"force" : 70,
        "dodge" : -5,
	"lvl" : 0,
	"damage": 15,
	        "damage_type" : "刺伤"
]),
([	"action" : "$N俯身斜倚，左手半推，右手一式「九指问镖」，向$n的$l划过",
	"force" : 90,
        "dodge" : 5,
	"lvl" : 0,
	"damage": 30,
	        "damage_type" : "刺伤"
]),
([	"action" : "$N双目微睁，一式「露草斜阳」，双手幻化出千百个指影，拂向$n的$l",
	"force" : 120,
        "dodge" : 5,
	"damage": 40,
	"lvl" : 9,
	        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「仰月承霖」，左掌护住丹田，右手斜指苍天，蓄势点向$n的$l",
	"force" : 160,
        "dodge" : 15,
	"damage": 80,
	"lvl" : 18,
	        "damage_type" : "刺伤"
]),
([	"action" : "$N双掌平托胸前，十指叉开，一式「叶底留莲」，指向$n的周身大穴",
	"force" : 210,
        "dodge" : 20,
	"damage": 120,
	"lvl" : 27,
	        "damage_type" : "刺伤"
]),
([	"action" : "$N双掌翻飞，一式「清风拂桂」，指端迸出无数道劲气，射向$n的全身",
	"force" : 270,
        "dodge" : 25,
	"damage": 160,
	"lvl" : 36,
	        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「菊圃秋霜」，并指如刃，一束束锐利无俦的刀气，凌虚向$n的$l砍去",
	"force" : 340,
        "dodge" : 30,
	"damage": 200,
	"lvl" : 45,
	        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「游水微笑」，双手食指交叉，指端射出一缕罡气，穿过$n的$l",
	"force" : 420,
        "dodge" : 35,
	"damage": 240,
	"lvl" : 55,
	        "damage_type" : "刺伤"
]),
([	"action" : "$N左掌竖立胸前，一式「太医搭脉」，右手食指扣住拇指，轻轻对着$n一弹",
	"force" : 510,
        "dodge" : 50,
	"damage": 450,
	"lvl" : 62,
	        "damage_type" : "刺伤"
]),
});

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练指镖必须空手。\n");
	if ((int)me->query_skill("yiqiguanforce", 1) < 50)
		return notify_fail("你的日月神功火候不够，无法学指镖。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练指镖。\n");
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
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练指镖。\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("xianren") + "/zhibiao/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({
        "$n使出一招「傲血九指」，无名指化作一条长虹，磕开了$N的$w。\n",
        "$n使出「粘」字诀，将$N的$w封于丈外。\n",
        "$n使出一招「飞雪连天」，无名指化做漫天雪影，荡开了$N的$w。\n",
        "$n一招「点石成金」，向$N拿$w的手腕点去。\n",
});

string *unarmed_parry_msg = ({
         "$n使出一招「傲血九指」，无名指化作一条长虹，磕开了$N的$w。\n",
        "$n使出「粘」字诀，将$N的$w封于丈外。\n",
        "$n使出一招「飞雪连天」，无名指化做漫天雪影，荡开了$N的$w。\n",
        "$n一招「点石成金」，向$N拿$w的手腕点去。\n",
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
