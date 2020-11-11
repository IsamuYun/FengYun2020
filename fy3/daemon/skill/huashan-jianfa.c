// huashan-jianfa.c ��ɽ����

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ�С����Ƴ�ᶡ�������$w����$n��$l",
	"damage" : 20,
	"damage_type" : "����"
]),
([	"action" : "$Nʹ�����з����ǡ���$w��˸����������$n��$l",
	"damage" : 25,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����������$w���϶��»���һ���󻡣���$n������ȥ",
	"damage" : 30,
	"damage_type" : "����"
]),
([	"action" : "$N��ǰ����һ��������$wʹ�����׺���ա�ֱ��$n��$l",
	"damage" : 35,
	"damage_type" : "����"
]),
([      "action" : "$N���е�$wһ�Σ�ʹ��������ӭ�͡�ֱ��$n��$l",
        "damage" : 50,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 20)
		return notify_fail("��Ļ�ɽ�ڹ����̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("���������������ɽ������\n");
	me->receive_damage("kee", 30);
	return 1;
}

string perform_action_file(string action)
{
	 return CLASS_D("huashan") + "/huashan-jianfa/" + action;
}

int effective_level() { return 9;}

string *parry_msg = ({
        "$n�Թ����أ�$vֱ��$N��ȥ��$N�ŵ����������������˹��ơ�\n",
        "$nʹ��һ�С�ɽ�����ܡ�����ȫ�������$v�γɵĽ�Ļ�С�\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v�����̳�����ס$N��ȫ�����ơ�\n",
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
        return -10;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 30;
}

