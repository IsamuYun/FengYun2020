inherit SKILL;
mapping *action = ({
        ([      "action":               "$Nʹһ�С�ǽ����֧÷������׼$n��$l������ָ",
                "force":                300,
                "parry":                200,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N���Ƴ��黨ָ״��һ�С��躮���Կ�������$n��$l�к���ȥ",
                "force":                400,
                "parry":                100,
                "damage_type":  "����"
        ]),
        
});
int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("����ɽ��÷�ֱ�����֡�\n");
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
int effective_level() { return 22;}
string *parry_msg = ({
        "$n����Ϊ����һ�С�ң֪����ѩ�����ͻ�$N��$w������\n",
});
string *unarmed_parry_msg = ({
        "$n���ƺ󳷣������Ա���һ�С�Ϊ�а�����������$N���ڳ��⡣\n",
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
        return -300;
}
int practice_bonus()
{
        return -300;
}
int black_white_ness()
{
        return 60;
}

