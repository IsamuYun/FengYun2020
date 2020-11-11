// TIE@FY3
inherit SKILL;
mapping *action = ({
([      "action": "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����$n��$l",
        "dodge": -30,
        "parry": 10,
        "force": 400,
        "damage_type": "����"
]),
([      "action": "$NͻȻ���η���˫�ƾӸ�����һ�С��������졹����$n��$l",
        "dodge": -15,
        "parry": -20,
        "force": 180,
        "damage_type": "����"
]),
([	"action": "$N����һ�С����������Ѹ���ޱȵ�����$n��$l",
	"dodge": -10,
	"parry": -10,
	"force": 120,
	"damage_type": "����"
]),
([	"action": "$N˫��ʩ��һ�С��轥��½�����������ŷ�������$n��$l",
        "dodge": -15,
	"parry": -10,
	"force": 160,
	"damage_type": "����"
]),
([	"action": "$N���ƾ۳�ȭ״������һ�С�Ǳ�����á���������$n��$l",
	"dodge": -10,
	"parry": 10,
	"force": 200,
	"damage_type": "����"
]),
([	"action": "$Nʩ��һ�С�����󴨡������Ʋ�������������$n��$l",
	"dodge": -10,
	"parry": 20,
	"force": 250,
	"damage_type": "����"
]),
([	"action": "$Nʹ����ͻ�������������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",
	"dodge": 0,
	"parry": 10,
	"force": 100,
	"damage_type": "����"
]),
([	"action": "$N���һ����˫��ʹ�����𾪰��������һ�а����$n",
	"dodge": -25,
	"parry": -10,
	"force": 300,
	"damage_type": "����"
]),
([	"action": "$Nʹ������Ծ��Ԩ������$n��$l��������",
	"dodge": -20,
	"parry": -20,
	"force": 230,
	"damage_type": "����"
]),
([	"action": "$N���λ�����˫��ʹһ�С�˫��ȡˮ��һǰһ����$n��$l",
	"dodge": -10,
	"parry": 20,
	"force": 160,
	"damage_type": "����"
]),
([	"action": "$Nʹ������Ծ��Ԩ�������η���˫�Ʋ���һ����$n��$l����",
	"dodge": -20,
	"parry": 30,
	"force": 250,
	"damage_type": "����"
]),
([	"action": "$N˫������ʹ����ʱ����������$n��������",
	"dodge": -20,
	"parry": 20,
	"force": 270,
	"damage_type": "����"
]),
([	"action": "$Nʹ�������Ʋ��꡹�����Ʒ�ס$n����·������бб������$l",
	"dodge": -15,
	"parry": 20,
	"force": 220,
	"damage_type": "����"
]),
([	"action": "$Nʹ�����������ڡ���˫�������������$n��$l",
	"dodge": -25,
	"parry": 10,
	"force": 350,
	"damage_type": "����"
]),
([	"action": "$N����һת��ͻȻ�۵�$n��ǰ��һ�С���ս��Ұ������$n��$l",
	"dodge": -20,
	"parry": 40,
	"force": 330,
	"damage_type": "����"
]),
([	"action": "$N�Ż��󿪣�һ�С���˪��������$n��$l��ȥ",
	"dodge": -25,
	"parry": 1,
	"force": 320,
	"damage_type": "����"
]),
([	"action": "$Nʹ��������ެ����˫���������ϻ���$n��$l",
	"dodge": -15,
	"parry": 40,
	"force": 200,
	"damage_type": "����"
]),
([	"action": "$N���ƻ��أ�����ʹһ�С�������β�����»ζ��Ż���$n��$l",
	"dodge": -10,
	"parry": 40,
	"force": 220,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ʮ���Ʊ�����֡�\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������̫�����޷�������ʮ���ơ�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 20)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("�����������������ʮ���ơ�\n");
	me->receive_damage("kee", 10);
	me->add("force", -10);
	return 1;
}

int effective_level() { return 23;}

int learn_bonus()
{
        return -20;
}
int practice_bonus()
{
        return -50;
}
int black_white_ness()
{
        return 100;
}

string perform_action_file(string action)
{
        return CLASS_D("beggar") + "/dragonstrike/" + action;
}

string *parry_msg = ({
        "$n˫��΢�֣�ʹ��һ�С�������β������ž����һ����$N��$w������\n",
        "$n��һת��һ�С������������$N����$w���֡�\n",
        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n����������һ�С��𾪰������ĳ����ƣ��Ƶ�$N�����Ա���\n",
        "$nʩչ����������β�������赭д�Ļ�����$N�Ĺ��ơ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

