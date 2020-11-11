// fonxansword.c

inherit SKILL;

mapping *action = ({
([	"action" : "$N����̧�ۣ���ָ���˸���Ȧ��һʽ��ָ�����⡹����$n��$l",
	"force" : 60,
        "dodge" : -5,
	"lvl" : 0,
	"damage": 10,
		"damage_type" : "����"
]),
([	"action" : "$N�������У�һʽ����÷�������ָ��Ҹ������ָ��$n����ǰ",
	"force" : 70,
        "dodge" : -5,
	"lvl" : 0,
	"damage": 15,
	        "damage_type" : "����"
]),
([	"action" : "$N����б�У����ְ��ƣ�����һʽ����ָ���ڡ�����$n��$l����",
	"force" : 90,
        "dodge" : 5,
	"lvl" : 0,
	"damage": 30,
	        "damage_type" : "����"
]),
([	"action" : "$N˫Ŀ΢����һʽ��¶��б������˫�ֻû���ǧ�ٸ�ָӰ������$n��$l",
	"force" : 120,
        "dodge" : 5,
	"damage": 40,
	"lvl" : 9,
	        "damage_type" : "����"
]),
([	"action" : "$Nһʽ�����³��ء������ƻ�ס�������бָ���죬���Ƶ���$n��$l",
	"force" : 160,
        "dodge" : 15,
	"damage": 80,
	"lvl" : 18,
	        "damage_type" : "����"
]),
([	"action" : "$N˫��ƽ����ǰ��ʮָ�濪��һʽ��Ҷ����������ָ��$n�������Ѩ",
	"force" : 210,
        "dodge" : 20,
	"damage": 120,
	"lvl" : 27,
	        "damage_type" : "����"
]),
([	"action" : "$N˫�Ʒ��ɣ�һʽ�������𡹣�ָ�˱ų�����������������$n��ȫ��",
	"force" : 270,
        "dodge" : 25,
	"damage": 160,
	"lvl" : 36,
	        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��������˪������ָ���У�һ����������ٱ�ĵ�����������$n��$l��ȥ",
	"force" : 340,
        "dodge" : 30,
	"damage": 200,
	"lvl" : 45,
	        "damage_type" : "����"
]),
([	"action" : "$Nһʽ����ˮ΢Ц����˫��ʳָ���棬ָ�����һ�����������$n��$l",
	"force" : 420,
        "dodge" : 35,
	"damage": 240,
	"lvl" : 55,
	        "damage_type" : "����"
]),
([	"action" : "$N����������ǰ��һʽ��̫ҽ������������ʳָ��סĴָ���������$nһ��",
	"force" : 510,
        "dodge" : 50,
	"damage": 450,
	"lvl" : 62,
	        "damage_type" : "����"
]),
});

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ָ�ڱ�����֡�\n");
	if ((int)me->query_skill("yiqiguanforce", 1) < 50)
		return notify_fail("��������񹦻�򲻹����޷�ѧָ�ڡ�\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������̫�����޷���ָ�ڡ�\n");
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
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("�������������ָ�ڡ�\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("xianren") + "/zhibiao/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({
        "$nʹ��һ�С���Ѫ��ָ��������ָ����һ�����磬�Ŀ���$N��$w��\n",
        "$nʹ����ճ���־�����$N��$w�������⡣\n",
        "$nʹ��һ�С���ѩ���졹������ָ��������ѩӰ��������$N��$w��\n",
        "$nһ�С���ʯ�ɽ𡹣���$N��$w�������ȥ��\n",
});

string *unarmed_parry_msg = ({
         "$nʹ��һ�С���Ѫ��ָ��������ָ����һ�����磬�Ŀ���$N��$w��\n",
        "$nʹ����ճ���־�����$N��$w�������⡣\n",
        "$nʹ��һ�С���ѩ���졹������ָ��������ѩӰ��������$N��$w��\n",
        "$nһ�С���ʯ�ɽ𡹣���$N��$w�������ȥ��\n",
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
	return 0;
}
