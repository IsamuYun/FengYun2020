// TIE@FY3
inherit SKILL;
mapping *action = ({
([      "action": "$Nʹ��һ�С�����˫Ȯ��������$w���������������$n��$l",
        "dodge": -10,
        "damage": 30,
        "damage_type": "����"
]),
([      "action": "$N����$w���һζ���һ�С�����Ѱ�ߡ���$n��$l��ȥ",
        "dodge": -20,
        "damage": 40,
        "damage_type": "����"
]),
([      "action": "$N����$w���Ӹ�����ʹһ�С���ݾ��ߡ�����$n��$l",
        "dodge": -30,
        "damage": 50,
        "damage_type": "����"
]),
([      "action": "$Nʩ�����������졹��$w����������$n��ȥ",
        "dodge": -20,
        "damage": 40,
        "damage_type": "����"
]),
([      "action": "$Nʩչ���򹷰����еġ��ذ���������$w��$nҪ����ȥ",
        "dodge": -20,
        "damage": 40,
        "damage_type": "����"
]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 25 )
                return 
notify_fail("���������������Ҳ�����һ����������ǿ������\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return 
notify_fail("���������һ��ľ�����������Ƶ�������������������\n");

        if( (int)me->query("kee") < 60 )
                return 
notify_fail("����������������Ź�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 60);
        return 1;
}
int effective_level() { return 21;}
 
string *parry_msg = ({
        "���$n�����е�$v����$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
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
	return -50;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("beggar") + "/dagou-stick/" + action;
}

