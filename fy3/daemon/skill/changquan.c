// liuh-ken.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ�С��ڻ����ġ�����׼$n��$l��������һȭ",
		"force":		40,
		"parry":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$N����ȭͷ��һ�С�̩ɽѹ��������$n��$l�к���ȥ",
		"force":		30,
		"parry":		10,
		"damage_type":	"����"
	]),
	([	"action":		"$N������Σ���ȭ���й�ֱ��������$n��$l����",
		"force":		30,
		"parry":		10,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һ������ȭ��������ȭʹ�����Ϻ��Ƴ�������$n$l",
		"force":		30,
		"parry":		20,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�����ֳ�ȭ������֡�\n");
	return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	return notify_fail("���ֳ�ȭֻ��ͨ����ʦ��ѧϰ��������\n");
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$n����Ϊ����һ�С�����Ϊ�������ͻ�$N��$w������\n",
});

string *unarmed_parry_msg = ({
        "$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",

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
	return 100;
}

string perform_action_file(string action)
{
        return CLASS_D("official") + "/changquan/" + action;
}
string belong()
{
	return "official";
}
