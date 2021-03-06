// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
	([	"action":		"$N手中火光一现照向$n的$l",
		"force":		400,
                "damage":               200,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一招[火光冲天]，烈火焚风裹向$n的$l",
                "damage":               200,
		"force":		300,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"火烟中$N象狂风中的流云，忽聚忽散出掌击向$n的$l",
		"force":		100,
                "damage":               200,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N和着火光，纵火散向$n的$l",
		"force":		100,
                "damage":               200,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N聚起全身的功力，双手打出火团飞向$n",
		"force":		200,
		"damage":		200,
		"damage_type":	"瘀伤"
	]),
});

int valid_learn(object me)
{
        if( (int)me->query_skill("force", 1) < 100 )
                return
                notify_fail("你的内功心法火候不足，无法练金殿纵火法。\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="unarmed") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够练这门功夫，还是先休息休息吧。\n");
	me->receive_damage("kee", 40);
	return 1;
}
int effective_level() { return 25;}

string *parry_msg = ({
	"$n慢慢伏身，突然一团火焰将$N逼得连退几步。\n",
});

string *unarmed_parry_msg = ({
        "$n手中一道火光封向$N。\n",
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
	return -5;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("quanli") + "/jindian-fire/" + action;
}

