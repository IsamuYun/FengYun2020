// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
	([	"action":		"$N手中的$w迎风一晃，刀锋带出裂锦般的声音，万马奔腾般地砍向$n的$l",
		"force":		400,
                "damage":               500,
		"damage_type":	"砍伤"
	]),
	([	"action":		"$N聚起全身的功力，手中的$w象刺骨寒风般割向$n",
		"force":		500,
		"damage":		600,
		"damage_type":	"砍伤"
	]),
});

int valid_learn(object me)
{
        if( (int)me->query_skill("force", 1) < 150 )
                return
                notify_fail("你的内功心法火候不足，无法练雁歌刀法。\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("你必须先找一把刀，才能练刀法。\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
	me->receive_damage("kee", 40);
	return 1;
}
int effective_level() { return 25;}

string *parry_msg = ({
	"$n慢慢地将手中的$v立于身前，强烈的刀风将$N逼得连退几步。\n",
});

string *unarmed_parry_msg = ({
        "$n手中的$v慢慢地挥出，剧烈颤动的刀锋封向$N。\n",
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
        return CLASS_D("yihua") + "/yanyu-blade/" + action;
}

