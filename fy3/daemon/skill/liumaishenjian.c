inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N�ͺ�һ��,����ȫ����,˫��Ĵָһ��,һ�ɳ��ȸ��͵Ľ������ڵ�������$n$l��ɲʱ������Ѹ�׼��磬�໥��ײ��,�����ɵ�",
                "dodge":                -30,
                "parry":                30,
                "force":                80,
                "damage_type":  "����",
                "weapon":               "���͵Ľ���",
        ]),
        ([      "action":               
"$NĬ������,������ָ������һ�ӡ�������������$n��$l",
                "dodge":                -30,
                "parry":                30,
                "force":                60,
                "damage_type":  "����",
                "weapon":               "��������",
        ]),
        ([      "action":               

"$N����Ȼ�ӿ�,���֡��ٳ彣�������$n����·ȫ����ɱ�����֡����󽣡�����$n��$l",
                "dodge":                -30,
                "parry":                30,
                "force":                70,
                "damage_type":  "����",
                "weapon":               "һ��ָ��",
        ]),
        ([      "action":               
"$N�������˾Ŵ�����,ȫ��������ӯ,���²���,���֡����󽣡������ٳ彣���������̽���һ�����$n��$l",
                "dodge":                -30,
                "parry":                30,
                "force":                140,
                "damage_type":  "����",
                "weapon":               "��������",
        ]),
        ([      "action":               
"$N����Ĵָ����,ʹ�������̽���,ָ������������������õش���$n��$l",
                "dodge":                -30,
                "parry":                30,
                "force":                90,

                "damage_type":  "����",
                "weapon":               "һ������",
        ]),
        ([      "action":               
"$N���һ��,Ĵָһ�ﵤ��������ӿ������ʹ�������̽�������$n��$l��ɲʱ�佣���ݺᣬ����������Ѹ�׼����໥��ײ��",
                "dodge":                -30,
                "parry":                30,
                "force":                100,
                "damage_type":  "����",
                "weapon":               "��������",
        ]),      
});

int valid_learn(object me) 
{
        int extra;
   //     if( (string)me->query("gender") != "����" )
   //             return notify_fail("��������ֻ�����Ӳ��������书��\n");
        extra = me->query_skill("duan-yiyangzhi",1);
        if ( extra < 220) 

                return notify_fail("��Ķ���һ��ָ���������죬�޷�ѧϰ�����񽣣�\n");
        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�����񽣱�����֡�\n");
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
 
 int effective_level() { return 40;}

string *parry_msg = ({
        "$nһ�С����󽣡�������һָ��һ������������Ϣ�ĵ�����$N��$w��\n",
        "$n��ɫ���У�һ�С�����������ٿ��һָ�ݳ���һ���վ��Ľ�������$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n�����ָ��̤��ͦ�����ٳ彣�������г彣����������ָ���ס$N�������Ѩ��\n",

        "$n����������ţ�һ�С����̽�����һָ��������$N�Ƶ��������ˡ�\n",
        "$n����������Ӱ��һ�С��س彣���͵Ļӳ�һָ��һ����������$N��\n",
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
        return CLASS_D("dali") + "/unarmed/" + action;
}
