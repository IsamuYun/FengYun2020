// celestrike.c

inherit SKILL;

mapping *action = ({
        ([      "action":               "$N˫�ִ���$n�����������б���ƺ�Ҫ��$nˤ��",
                "parry":                30,
                "damage":                50,
                "dodge":                10,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��ס$n��$l����$n�ٹ�ͷ���������ºݺ�һˤ",
                "parry":                30,
                "damage":                50,
                "dodge":                10,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N˫��ǰ�죬�ƺ�Ҫץס$n��$l",
                "parry":                10,
                "damage":                50,
                "dodge":                30,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�䲻�������ţ���ͼ��$n�赹�ڵ���",
                "parry":                10,
                "damage":                80,
                "dodge":                30,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�ҽ���գ��γ�һƬ��Ӱ�����Ǽ���$n��$lһ���߳�����",
                "parry":                30,
                "damage":                70,
                "dodge":                10,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�����Ʊ�����֡�\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n����һ����˫��һ�ŵأ�ȫ����$N��$w�Ĺ�����Χ��\n",
});

string *unarmed_parry_msg = ({
        "$n����һ����˫��һ�ŵأ�ȫ����$N�Ĺ�����Χ��\n",
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
	return 5;
}
int black_white_ness()
{
	return -10;
}

