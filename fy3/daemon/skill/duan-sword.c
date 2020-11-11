// fonxansword.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹһ�С����߳�����������$w��һ�����߰����$n��$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����Ͻ����еġ���ɽ������������ն��$n��$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�������С������ζ�Ȼ�������ߣ�����$wն��$n��$l",
                "dodge":                -30,
		"damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ��ɽ�������׼$n��$l�̳�һ��",
                "dodge":                -40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ�С��������ա���׼$n��$lбб�̳�һ��",
                "dodge":                -40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��һ�С����񳯷����$n��$l",
                "dodge":                20,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               

"$N����$w����һ�֣�ʹһ�С��������������ֶ�׼$n$lһ����ȥ",
                "dodge":                -20,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ�С��������ơ�����һ���⻡����$n��$l",
                "dodge":                -30,
                "damage":               50,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취�����Ͻ�����\n");


        if( (string)me->query_skill_mapped("force")!= "duan-force")
                return notify_fail("���Ͻ���������϶����ķ���������\n");

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
notify_fail("�����������������û�а취��ϰ���Ͻ�����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ����Ͻ�����\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("dali") + "/sword/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({

        "$nʹ��һ�С��ʵ��ɷɡ������е�$v����һƬ��Ӱ���Ŀ���$N��$w��\n",
        "$nʹ�����⡹�־�����$N��$w�������⡣\n",
        "$nʹ��һ�С�����ϸ�꡹�����е�$v��������ˮ�Σ�������$N��$w��\n",
        "$n���е�$vһ����һ�С����ﳯ��������$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С��������졹����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С�����񡹣�$vֱ��$N��˫�֡�\n",
        "$n�����е�$v���������ɵ����ȵ�$N�������ˡ�\n",
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