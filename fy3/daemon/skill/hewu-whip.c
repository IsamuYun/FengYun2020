// chixie-whip.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "������",
                "action":               "$Nʹ���������ơ�������$w���ñ�ֱ��$n��$l��������",
                "dodge":                -10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "������",
                "action":               "$N����һת��һ�ơ������ơ�$w�ó������Ӱ������ʵʵ��Ϯ��$n��$l",
                "dodge":                -50,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ɽ��",
                "action":               "$N����$w��һ�ơ���ɽ�ơ�����ӰƮ�������ص���$n��$l",
                "dodge":                -40,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "������",
                "action":               "$N����$wһ����һ�ơ������ơ���һ������ĽǶ���$n���̾�ȥ",
                "dodge":                -40,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([
                "name":                 "������",
                "action":               "$N����һ����ʹһ�ơ������ơ�������$wһ�޽���һ�޲�ͣ�س���$n��$l",
                "dodge":                -50,
                "damage":               100,
                "damage_type":   "����"
        ]),
        ([      "name":                 "������",
                "action":               "$Nһ�С������ơ�����$w���һƬ��Ӱɨ��$nȫ��",
                "dodge":                -60,
                "damage":               150,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("�������������û�а취�����ڱ޷�, ����Щ���������ɡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ������޷���\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ���ڱ޷���\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ����ڱ޷���\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

int effective_level() { return 15;}

string *parry_msg = ({
        "$n���е�$vһ����������Ȼҧ��$N����ۡ�\n",
        "$nһ�����е�$v��ʹ��һ�ơ������ơ�������ֱ��$N�Ļ��ڡ�\n",
        "$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
        "$nʹ��һ�ơ������ơ����Ƶ�$N�˳����⡣\n",
        
});

string *unarmed_parry_msg = ({
        "$n���е�$vһ����������Ȼҧ��$N����ۡ�\n",
        "$nһ�����е�$v��ʹ��һ�ơ������ơ�������ֱ��$N�Ļ��ڡ�\n",
        "$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
        "$nʹ��һ�С������ơ����Ƶ�$N�˳����⡣\n",
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
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 20;
}