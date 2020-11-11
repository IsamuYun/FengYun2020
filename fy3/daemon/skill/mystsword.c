// mystsword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "ĺѩ��̾",
                "action":               "$Nʹһ�С�ĺѩ��̾��������$w���������ش���$n$l",
                "dodge":                -30,
                "damage":               60,
                "damage_type":  "����"
        ]),
        ([      "name":                 "����Ū��",
                "action":               "$N����һ�Σ�һ�С�����Ū�ѡ���$n$l�̳�һ��",
                "dodge":                -20,
                "damage":               80,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���Ȱ���",
                "action":               "$N�趯$w��һ�С����Ȱ�����Ю�������������$n��$l",
                "dodge":                -40,
                "damage_type":  "����"
        ]),
        ([      "name":                 "޹�����",
                "action":               "$N����$wһ��Ȧת��ʹ����޹����硹�з�ֱ������$n��$l",
                "dodge":                -30,
                "damage":               100,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_skill("mystforce",1) < 30 )
                return notify_fail("��Ĳ����ķ���򻹲�����\n");

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취��С��������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰС��������\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ��С��������\n");
        return 1;
}

int effective_level() { return 7;}

int learn_bonus()
{
        return 40;
}
int practice_bonus()
{
        return 20;
}
int black_white_ness()
{
        return 30;
}

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

