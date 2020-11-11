// spring-blade.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С����������������$w��ƮƮ����$n��$lնȥ��",
		"damage":		100,
		"dodge":		70,
		"damage_type":	"����"
	]),
	([	"action":		"$N�������磬$w����һ�С�Զɽ���˳ա����¶�������$n��$l",
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һת��һ�С��ɻ������㡹$w���ⲻ����ն��$n��$l",
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N�趯$w��һ�С���Ҷ����Ц��Ѹ�����׵�����$n��$l",
		"damage_type":	"����"
	]),
	([	"action":		"$N����$wһ�Σ�һ�С�ٻӰ����������$n��$lбб����һ��",
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N�ᵶ���磬�������һ�С�«ѩ����Ӱ��ֱ��$n$l",
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N�Ʋ�����ʹһ�С��ʵ������¡��������ն��$n��$l",
		"damage":		40,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
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
int effective_level() { return 20;}

string *parry_msg = ({
        "$nʹ��һ�С�����ͼ���𡹣������е�$v����$N����ָ��\n",
	"$n���̤ǰһ����һ�С����紵б���������е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n",
	"$n���е�$vһ�������һƬ������һ�С�����Ϧ����������$N��ȫ��\n",
	"$n΢��һ�������е�$v����һ��Բ����һ�С����߲�֪�ء�����$N��ȫ��Χס��\n",
});

string *unarmed_parry_msg = ({
"$nʹ��һ�С�����ͼ���𡹣������е�$v����$N����ָ��\n",
"$n���̤ǰһ����һ�С����紵б���������е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n",
"$n���е�$vһ�������һƬ������һ�С�����Ϧ����������$N��ȫ��\n",
"$n΢��һ�������е�$v����һ��Բ����һ�С����߲�֪�ء�����$N��ȫ��Χס��\n",
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
	return -100;
}
int black_white_ness()
{
	return 20;
}

