//TIE@FY3
inherit SKILL;
mapping *action = ({
	([	"action":		"$Nʹһ�С������ˮ�����ס�������$w��������б������ɳ��ʯ����ס$n�Ķ�Ŀ������һ������$n��$l��",
		"dodge":		-870,
		"parry":		-700,
		"damage_type":	"����"
	]),
	([	"action":		"$N���μ�ת�������˶���$w����һ�С�������ɼ��ѡ������������$n��$l��ȥ��",
                "dodge":                -670,
                "parry":                -600,
		"damage_type":	"����"
	]),
	([	"action":		"$N����Ծ���ն�����$w��һ�С������˺������ڡ����������$n��$l",
                "dodge":                -570,
                "parry":                -500,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w�趯���������ƣ�һ�С����ƴ��������Ρ���������˷�������$nɱȥ��",
                "dodge":                -470,
                "parry":                -400,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w����ƬƬ���⣬һ�С��ĵس�Ʈ����ѩ����ƮƮ������$n��ȥ",
                "dodge":                -370,
                "parry":                -200,
		"damage_type":	"����"
	]),
	([	"action":		"$N�����ĳ����Ʒ����ң�����Ϯ�ˣ�����$w������ʹ⻪��һ�С����ڷ�����ɫ����ֱ��$n$l",
                "dodge":                -270,
                "parry":                -100,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹһ�С�������������ɡ�������$w��ת�������������ն��$n��$l",
                "dodge":                -170,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
        object ob;

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
int effective_level() { return 8;}

string *parry_msg = ({
        "$nʹ��һ�С�����������������е�$v������������$N��$w��\n",
	"$n����$v�����������⣬����ɭɭ��һ�С������¹�����������Ӳ��滮��$N֮�ؾȡ�\n",
	"$n����ת�������е�$v�⻪������һ�С��������ɰ���ơ�������$N��$w��\n",
});

string *unarmed_parry_msg = ({
"$nʹ��һ�С���ţ�뺣�沨ɢ�������е�$v��Ȼ������$N�Ĺ����沨��ɢ��\n",
"$nվ�����Σ�����$v���Ⱪ����һ�С���ұ����ɫ���⡹����ס$N����ʽ��\n",
"$n���е�$v���л�ʽ���������ࡣ\n",
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
	return 100;
}
int practice_bonus()
{
	return 50;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/lianxin-blade/" + action;
}

