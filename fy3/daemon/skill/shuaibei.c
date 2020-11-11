// celestrike.c

inherit SKILL;

mapping *action = ({
        ([      "action":               "$N���ƻ��أ���ȭ�����󷢣�һʽ����������������������$n��$l",
                "parry":                20,
                "force":                30,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹһʽ���ƶ����롹�����������������ɺ����һ��˦����ն��$n��$l",
                "parry":                20,
                "force":                30,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N���Ʊ�������һ������һʽ�����б��¡���˫�Ƽ�����$n�ļ�ͷ",
                "parry":                50,
                "force":                30,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N���ƻ�һ��Բ��һʽ��������ա�������б������������$n����ǰ��Ѩ",
                "parry":                30,
                "force":                30,
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
        "$n�ֽ�һ������Ӳ��Ӳ��$N���岽��\n",
});

string *unarmed_parry_msg = ({
        "$n������Σ��������$N��Ҫ�������������С�\n",
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

