// bai-quan.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С����ɲ��¡�����׼$n��$l��������һȭ",
		"dodge":		-60,
		"parry":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����ȭͷ��һ�С���ѩ��ɽ������$n��$l�к���ȥ",
		"dodge":		-70,
		"parry":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$N������Σ���ȭ����ɽ���Ρ���$n��$l����",
		"dodge":		-80,
		"parry":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һ������ȭ��������ȭʹ�����������졹����$n$l",
		"dodge":		-90,
		"parry":		30,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("����ɽ�Ʒ�������֡�\n");
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
	if( (int)me->query("kee") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 7;}

string *parry_msg = ({
        "$nһ�С�����һ�ߡ����ͻ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
        "$n��ȭ��ϣ���ȭһ�С�����Ϊ�������Ƶ�$N����������\n",
        "$n����Ϊ����һ�С�ʨ��Ի͡����ͻ�$N��$w������\n",
        "$nһ�С����Ρ�������һ��$N��$w���֣���ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$nһ�С�������������Ƶ�$N��;���С�\n",
        "$n����������һ�С����׳�н������$N֮�ؾȡ�\n",
        "$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",
        "$n˫ȭ�����ʹ��һ�С�һ��˫�񡹣�$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",

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
        return CLASS_D("quanli") + "/hanshan-strike/" + action;
}

int learn_bonus()
{
	return 50;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 0;
}

