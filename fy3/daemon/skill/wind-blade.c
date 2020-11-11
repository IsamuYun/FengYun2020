// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
	([	"action":		"$N���е�$wӭ��һ�Σ���������ѽ���������������ڰ�ؿ���$n��$l",
		"force":		400,
                "damage":               200,
		"damage_type":	"����"
	]),
	([	"action":		"$N���е�$wӭ����裬�󱩷��еĹ�ɳ������$n��$l",
                "damage":               200,
		"force":		300,
		"damage_type":	"����"
	]),
	([	"action":		"$N���е�$w�����е����ƣ����ۺ�ɢ�ؿ���$n��$l",
		"force":		100,
                "damage":               200,
		"damage_type":	"����"
	]),
	([	"action":		"$N�ζ����е�$w������������֣�������е���Ҷ��һ����һ����ɢ��$n��$l",
		"force":		100,
                "damage":               200,
		"damage_type":	"����"
	]),
	([	"action":		"$N����ȫ��Ĺ��������е�$w��̹Ǻ�������$n",
		"force":		200,
		"damage":		200,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
        if( (int)me->query_skill("force", 1) < 10 )
                return
                notify_fail("����ڹ��ķ�����㣬�޷���ӭ��һ��ն��\n");
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
		return notify_fail("���������һ�ѵ���������������\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("kee", 40);
	return 1;
}
int effective_level() { return 25;}

string *parry_msg = ({
	"$n�����ؽ����е�$v������ǰ��ǿ�ҵĵ��罫$N�Ƶ����˼�����\n",
});

string *unarmed_parry_msg = ({
        "$n���е�$v�����ػӳ������Ҳ����ĵ������$N��\n",
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
        return CLASS_D("bandit") + "/wind-blade/" + action;
}

