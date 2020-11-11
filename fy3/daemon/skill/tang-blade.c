
inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С���꼸�֡�������$w���Ƶ���$n��$lնȥ��",
		"damage":		70,
		"dodge":		70,
		"damage_type":	"����"
	]),
	([	"action":		"$N�䵶���£�$w����һ�С������ʻ������¶�������$n��$l",
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һת��һ�С�����ƮƮ��$w�糯¶��˸��ն��$n��$l",
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N�趯$w��һ�С�ȥ�տ�ࡹ��$n��$lбб����һ��",
		"damage_type":	"����"
	]),
	([	"action":		"$N����$wһ�Σ�һ�С�����������Ѹ�����׵�����$n��$l",
		"damage":		70,
		"damage_type":	"����"
	]),
	([	"action":		"$N�����������զչ��һ�С�������ֱ��$n$l",
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$N�Ʋ�����ʹһ�С��λ����塹����ն��$n��$l",
		"damage":		50,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취�����������\n");

        if( (string)me->query_skill_mapped("force")!= "tangforce")
                return notify_fail("�������������������в�������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�������������\n");
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
        "$nʹ��һ�С�����һ�����������е�$v����$N����ָ��\n",
	"$n���̤ǰһ����һ�С����໨�꡹�����е�$v�Ӳ���Ʈ��$N֮�ؾȡ�\n",
	"$n���е�$vһ�������һƬ������һ�С��������ġ�������$N��ȫ��\n",
	"$n΢��һ�������е�$v����һ���⻡��һ�С��Ի����ѡ�����$N��ȫ��Χס��\n",
});

string *unarmed_parry_msg = ({
"$nʹ��һ�С��������񡹣������е�$v����$N��\n",
"$n���̤ǰ̤��һ�С�һ�����¡������е�$v����$N֮�ؾȡ�\n",
"$n���е�$vһ����һ�С�ɽ��ˮԶ��������$N��\n",
"$n���е�$v����һ�С�����һʫ������$N��ȫ��Χס��\n",
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
	return -50;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
        return CLASS_D("tangmen") + "/tang-blade/" + action;
}

