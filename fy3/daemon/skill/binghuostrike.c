// spicyclaw.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N���Ƴʺ�ɫ,һ�ɾ޴����������$n!",
		"dodge":		-30,
		"parry":		-70,
		"force":		460,
		"damage_type":	"ץ��"
	]),
	([	"action":		"$N���Ƴʰ�ɫ,һ��ǿ�����������$n!",
		"dodge":		-70,
		"parry":		-40,
		"force":		580,
		"damage_type":	"����"
	]),
	([	"action":		"$N����˫�����,ͻȻ�ֿ�,˲�䱬����:!��!��һ������!",
		"parry":		-90,
		"force":		600,
		"damage_type":	"ץ��"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�������һ��Ʊ�����֡�\n");
	if( (int)me->query("max_force") < 150 )
		return notify_fail("�������̫�����޷��������һ��ơ�\n");
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 25);
	me->add("force", -3);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/5) > victim->query_str() ) {
		victim->receive_wound("kee", (damage_bonus - 100) / 2 );
		switch(random(3)) {
			case 0: return "��������������һ�����죬�����ǹ����������\n";
			case 1: return "$N����һ�£�$n��$l������������һ�����죡\n";
			case 2: return "ֻ����$n��$l��������һ�� ...\n";
		}
	}
}
int effective_level() { return 18;}

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

string *parry_msg = ({
        "$n����$N�����ţ��Ƶ�$N��;�������е�$w��\n",
});

string *unarmed_parry_msg = ({
        "$n����$N�����ţ��Ƶ�$N��;���С�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
        return CLASS_D("yihua") + "/binghuostrike/" + action;
}


