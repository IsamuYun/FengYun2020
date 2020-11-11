// vivien-sword.c ��˼����

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹһ�С��������С�������$w��һ�����߰����$n��$l",
                "dodge":                10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ����˼�����еġ��������������������ն��$n��$l", 
                "dodge":                5,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�����ٻӰ��,����$w����Ϊ������$n��$l", 
                "dodge":                20,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ���������ࡹ��׼$n��$l�̳�һ��", 
                "dodge":                20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ�С�������ͷ����׼$n��$lбб�̳�һ��", 
                "dodge":                20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��һ�С�������ȥ������$n��$l", 
                "dodge":                10,
                "damage":               10,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ�С�����֮�������ֶ�׼$n$lһ����ȥ", 
                "dodge":                20,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ�С�����֮�ġ�����һ���⻡����$n��$l", 
                "dodge":                10,
                "damage":               50,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취����˼������\n");

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
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("�����������������û�а취��ϰ��˼������\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ����˼������\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("tiandi") + "/vivien-sword/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({
        "$nʹ��һ�С������������е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$nʹ�����������־�����$N��$w�������⡣\n",
        "$nʹ��һ�С��İ��������е�$v��������ѩӰ��������$N��$w��\n",
        "$n���е�$vһ����һ�С��ﰮ������$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С��������ա�����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С�������졹��$vֱ��$N��˫�֡�\n",
        "$n�����е�$v���������������ȵ�$N�������ˡ�\n",
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
	return 15;
}

