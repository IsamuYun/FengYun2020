inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹһ�С��ض�ɽҡ��������$w������������$n��$l",
                "dodge":                -20,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ���������еġ����̻��᡹�������������$n��$l",
                "dodge":                -20,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�ɽˮ���项�����ζ�ȻƮ�����ߣ�����$wն��$n��$l",
                "dodge":                -30,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ�����걩�硹��׼$n��$l��������",
                "dodge":                -40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ�С�����ɽ�ӡ���׼$n��$lбб����һ��",
                "dodge":                -40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w�ó����ؽ�Ӱ��һ�С������������$n��$l",
                "dodge":                20,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ�С��񽣳��졹���ֶ�׼$n$lһ����ȥ",
                "dodge":                -20,
                "damage":               50,
                "damage_type":  "����"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취����������\n");

        if( (string)me->query_skill_mapped("force")!= "wuwei-force")
                return notify_fail("���������������ķ���������\n");

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
notify_fail("�����������������û�а취��ϰ��������\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ���������\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("zhiyi") + "/sword/" + action;
}
 
int effective_level() { return 18;}

string *parry_msg = ({
        "$nʹ��һ�С�������������е�$v����һ���������Ŀ���$N��$w��\n",
        "$nʹ����������꡹����$N��$w�������⡣\n",
        "$nʹ��һ�С���ɳ��ʯ�������е�$v�������콣Ӱ��������$N��$w��\n",
        "$n���е�$vһ����һ�С�ĺ�»�Ӱ������$N��$w������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С������������������ʧ��һ������Ľ���֮�С�\n",
        "$nʹ��һ�С�������꡹��$vֱ��$N��˫�֡�\n",
        "$n�����е�$v����������Ӱ���ȵ�$N�������ˡ�\n",
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


