inherit SKILL;
mapping *action = ({
        ([      "action":               "$Nʹһ�С��������ࡹ����׼$n��$l��������һ��",
                "force":                400,
                "parry":                200,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�������ƣ�һ�С�������꡹����$n��$l�к���ȥ",
                "force":                500,
                "parry":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������Σ����ơ���������������$n��$l����",
                "force":                300,
                "parry":                300,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����һ�������ƺ���������ʹ��������ϸ�꡹����$n$l",
                "force":                200,
                "parry":                400,

                "damage_type":  "����"
        ]),
});
int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("����ɽ�����Ʊ�����֡�\n");
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
        if( (int)me->query("kee") < 90 )

                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("kee", 90);
        return 1;
}
int effective_level() { return 21;}
string *parry_msg = ({
        "$n����Ϊ����һ�С��������ա����ͻ�$N��$w������\n",
});
string *unarmed_parry_msg = ({
        "$n���ƻ��£������Ա���һ�С��������ơ�����$N���ڳ��⡣\n",
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

        return -5000;
}
int practice_bonus()
{
        return -5000;
}
int black_white_ness()
{
        return 50;
}
string perform_action_file(string action)
{
        return CLASS_D("piaomiao") + "/sixsun/" + action;
}

