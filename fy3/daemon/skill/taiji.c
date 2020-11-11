// taiji.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N˫��Բת��ʹ��һ�С�����β������׼$n��$l����",
		"dodge":		-30,
		"parry":		50,
		"damage_type":	"����"
	]),
	([	"action":		"$N������Σ����ƻ���һ��Բ����һ�С����ޡ�����$n��$l�к���ȥ",
		"dodge":		-20,
		"parry":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ�С��׺����᡹��˫�Ƴ�Բ��������Բת����$n��$l����",
		"dodge":		-20,
		"parry":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N����������������ʹ��һ�С��ֻ����á���˫��������$n��$l��£",
		"dodge":		-20,
		"parry":		40,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
        if((int)me->query("level") <40)
                return notify_fail("��ĵȼ���������ʮ����\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��̫��ȭ��������֡�\n");
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
 	return notify_fail("̫��ȭֻ��ͨ����ʦ��ѧϰ��������\n");
	return 1;
}
int effective_level() { return 20;}

string *parry_msg = ({
        "$nһ�С��������ơ���Բ���λ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
        "$n����̫����һ�С�§ϥ���������Ƶ�$N����������\n",
        "$n����Ϊ����һ�С����������������ͻ�$N��$w������\n",
        "$nһ�С�����Ʊա���˫�Ʋ���Բת������$N����������ת��һȦ��\n",
});

string *unarmed_parry_msg = ({
        "$nһ�С�ʮ���֡����Ƶ�$N��;���С�\n",
        "$n�����������Ծ��ƶ���һ�С�������ɽ������$N������Զ��\n",
        "$n����������������ʹ��̫��ȭ�ġ�����ʽ��������׾ٵؽ�$N���ڳ��⡣\n",
        "$n˫�������ʹ��̫��ȭ���һʽ�����޺�̫������$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",

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
	return -20;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
        return CLASS_D("wudang") + "/taiji/" + action;
}
string belong()
{
	return "wudang";
}
