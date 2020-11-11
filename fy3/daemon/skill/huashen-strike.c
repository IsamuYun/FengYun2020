inherit SKILL;
mapping *action = ({
        ([      "action":               
"$Nʹ��һ�С�������𡹣�������ӣ�һ�������������$n��$l",
                "dodge":                100,
                "parry":                100,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С���ĺ��;��������һ����Ӱ������������$n��$l",
                "dodge":               100,
                "parry":                100,
                "force":                 70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������Ʒ��еġ����᳤�硹���������죬һ������$n��$l",
                "dodge":               100,
                "parry":                100,

                "force":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���μ���������������Ӱ��ʹ��������ɽ�ӡ�����ӰͻȻ��Ϊһ�壬˫���ѵ���$n����ǰ",
                "dodge":                100,
                "parry":                100,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ���������ζ�����һ�С���ӿ���ȡ�����$n$l",
                "dodge":                100,
                "parry":                100,
                "force":                140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫�ƻζ�����һ����һ����ʹ���������ơ����Ʒ簵���޴��������ӿ��е�ͷ��$n��$l���ƹ���",
                "dodge":                200,

                "parry":                200,
                "force":                150,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�������Ʒ�������֡�\n");
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
        "$n˫��һ�֣�ʹ��һ�С������·�������ž����һ����$N��$w����˫��֮�䡣\n",
        "$n��һת��һ�С����ݴ��͡�����$N����$w���֡�\n",
        "$nʹ��������Ϊ�Ρ�������������˫��һ������ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n��������һ�С��Զ�����������ĳ����ƣ��Ƶ�$N�����Ա���\n",

        "$nʩչ������˷���롹�����赭д�Ļ�����$N�Ĺ��ơ�\n",
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
        return 10;
}

string perform_action_file(string action)
{
        return CLASS_D("moondoor") + "/huashen-strike/" + action;
}