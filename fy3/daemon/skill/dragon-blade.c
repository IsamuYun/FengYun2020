// dragon-blade.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹһ�С����ɷ��衹������$w����������㿳��$n��$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����������еġ����̻��᡹���������ն��$n��$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С����������������ζ�ȻƮ�����ߣ�����$wն��$n��$l",
                "dodge":                -30,

                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ����̶��Ѩ����׼$n��$l��������",
                "dodge":                -40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ�С����ڻ�Ծ����׼$n��$lбб����һ��",
                "dodge":                -40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w�ó����ص�Ӱ��һ�С������������$n��$l",
                "dodge":                20,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               

"$N����$w����һ�֣�ʹһ�С���Ǳ��Ԩ�����ֶ�׼$n$lһ����ȥ",
                "dodge":                -20,
                "damage":               20,
                "damage_type":  "����"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취������������\n");

 //       if( (string)me->query_skill_mapped("force")!= "jingyiforce")
 //               return notify_fail("���������������ķ���������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )

                return notify_fail("���������һ�ѵ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
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

notify_fail("�����������������û�а취��ϰ����������\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ�����������\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("dragon") + "/blade/" + action;
}
 
int effective_level() { return 18;}

string *parry_msg = ({
        "$nʹ��һ�С�������졹�����е�$v����һ���������Ŀ���$N��$w��\n",
        "$nʹ���������־�����$N��$w�������⡣\n",
        "$nʹ��һ�С����������������е�$v�������쵶Ӱ��������$N��$w��\n",
        "$n���е�$vһ����һ�С���Ӱ����������$N��$w������ȥ��\n",
});


string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С�����ͻ�֡�����������ʧ��һ������ĵ���֮�С�\n",
        "$nʹ��һ�С�������졹��$vֱ��$N��˫�֡�\n",
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