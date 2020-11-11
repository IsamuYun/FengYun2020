// tenderzhi.c

inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N����һ�ӣ�һ�С���¥���¡����ֵ���$n$l",
                "dodge":                -30,
                "parry":                30,
                "force":                80,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
        ([      "action":               
"$Nʹһ�С�ѩ����÷������Ӱ��ǰ���ᣬͻȻһת��������$n��$l��ȥ",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
        ([      "action":               
"$N���Զ٣�����һ��ʹ������ͤ��������$n��$l��ȥ",
                "dodge":                -30,
                "parry":                30,
                "force":                140,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
        ([      "action":               
"ֻ��$N����һ�ڣ���Ȼ�������ߣ�����˳������һ�С��ҷ��˵�����$n��$l��ȥ",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
});

int valid_learn(object me)
{
        if( (string)me->query("gender") != "Ů��" )
                return notify_fail("���ָ��ֻ��Ů�Ӳ��������书��\n");
        if((int)me->query("max_force") < 250 )
                return notify_fail("�������������\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�����ָ������֡�\n");
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
        if( (int)me->query("sen") < 30 )
                return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("������������ˡ�\n");

        me->receive_damage("sen", 30);
        me->add("force", -10);

        return 1;
}
 
int effective_level() { return 20;}

string *parry_msg = ({
        "$n��ָ΢��$N$w�ļ�ˣ�$N���е�$w�������ֶ�����\n",
});

string *unarmed_parry_msg = ({
        "$n�����ָ�������㣬ָ��ֱ��$N�������Ѩ��\n",
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
	return -100;
}
int practice_bonus()
{
	return -100;
}
int black_white_ness()
{
	return 50;
}

string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/tenderzhi/" + action;
}

