#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":               
HIC"$Nʹ��������ʽ�е����һʽ��������س��ݣ����е�$w"+HIC+"�����ֱ��$n"+HIC+"��$l��"NOR,
                "force" :               90,
                "damage_type":  "����"
        ]),
        ([      "action":               
HIC"$Nʹ��������ʽ�еĵ�һʽ�����ӳ���ɣݣ����е�$w"+HIC+"�����ֱ��$n"+HIC"��$l��"NOR,
                "force":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
HIC"$Nʹ��������ʽ�еĵڶ�ʽ����ɽ������ݣ����е�$w"+HIC+"�����ֱ��$n"+HIC+"��$l��"NOR,
                "force":               120,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취��������ʽ��\n");

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
        if( (int)me->query("kee") < 200
        ||      (int)me->query("force") < 300 )
                return 
notify_fail("�����������������û�а취��ϰ������ʽ��\n");
        me->receive_damage("kee", 150);
        me->add("force", -200);
        write("�㰴����ѧ����һ�������ʽ��\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("yihua") + "/feiyan-shenjian/" + action;
}
 
int effective_level() { return 25;}

string *parry_msg = ({
        "$n�������Ʈ�䣬����$vƽָ����������$N���գ�\n",
        "$n��������� ����׾ٵļ�ס��$N��$w��\n",
        "$n����һ���������е�$v����ǧ�ٽ�â����ס��ȫ��\n",
        "$n���е�$v���綶������ס��$N�����й��ơ�\n",
});

string *unarmed_parry_msg = ({
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
        return 100;
}
int practice_bonus()
{
        return 150;
}
int black_white_ness()
{
        return 50;
}