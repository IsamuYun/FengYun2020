
inherit SKILL;

mapping *action = ({
	([	"action":	"$N����$wбָ��һ�С�ͣ����·��������һ�٣�һ����$n��$l��ȥ",

		"damage":		70,
		"dodge":		70,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ�С�ͯ�ӹһ�������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$Nչ���鲽������Ծ�䣬һ�С��ƴ����¡�������һ������ն��$n",
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ�С����ż�ɽ����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
		"damage_type":	"����"
	]),
	([	"action":		"$N����$wһ����һ�С���Ϫ���㡹��˫�ֳ����������У�����$n���ؿ�",
		"damage":		70,
		"damage_type":	"����"
	]),
	([	"action":	 "$N����$w��ʹ��һ�С��Ź����ġ����������ã����ҿ�����������$n",
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ�С��������ۡ������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
		"damage":		50,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("����ڹ��ķ�������û�а취����ƽ�̱��С�\n");

        if( (string)me->query_skill_mapped("force")!= "wuchenforce")
                return notify_fail("��ƽ�̱��б�������޳��ķ���������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "dagger" )
                return notify_fail("���������һ��ذ�ײ�����������\n");
        return 1;
}

int valid_enable(string usage)
{
	return (usage=="dagger") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "dagger" )
		return notify_fail("���������һ��ذ�ף�������������\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 40);
	return 1;
}
int effective_level() { return 20;}

string *parry_msg = ({
        "$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ������$n��ȫ��ӿȥ��\n",
	"$Nʹ��һ�С��׷��ȡ�����ۻ��գ�����������ֱ��$n��$l,�ܵ�$n�������ˡ�\n",
	
});

string *unarmed_parry_msg = ({
        "$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ������$n��ȫ��ӿȥ��\n",
	"$Nʹ��һ�С��׷��ȡ�����ۻ��գ�����������ֱ��$n��$l,�ܵ�$n�������ˡ�\n",
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
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
        return CLASS_D("quanli") + "/yuping-dagger/" + action;
}

