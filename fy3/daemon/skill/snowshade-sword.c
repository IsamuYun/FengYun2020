// fonxansword.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С��ع�õ硹������$w��һ���������$n��$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ��ìɽѩӰ���еġ���˪��Ӱ����$w���ӽ������ն��$n��$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ�С�������ѩ��������Ʈ�����ߣ�����$wն��$n��$l",
		"dodge":		-30,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w�й�ֱ����һʽ�����ȳ��硹��׼$n��$l�̳�һ��",
		"dodge":		-40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һԾ������$wһ�С�������������׼$n��$lбб�̳�һ��",
		"dodge":		-40,
		"damage_type":	"����"
	]),
	([	"action":		"$N��$wƾ��һָ��һ�С���ʯ���̡�����$n��$l",
		"dodge":		20,
		"damage":		40,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취��ѩӰ������\n");


	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

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
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰѩӰ������\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ��ѩӰ������\n");
	return 1;
}
int effective_level() { return 11;}

int learn_bonus()
{
	return 30;
}
int practice_bonus()
{
	return 20;
}
int black_white_ness()
{
	return 30;
}

string *parry_msg = ({
        "���$n�����е�$v����$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
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
        return CLASS_D("taoist") + "/snowshade-sword/" + action;
}


