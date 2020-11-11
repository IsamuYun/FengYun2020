// liuh-ken.c

inherit SKILL;

mapping *action = ({
        ([      "action":               "$Nʹһ�С���ȭ������׼$n��$l��������һȭ",
                "force":                40,
                "parry":                20,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����ȭͷ��һ�С��ҹ�ȭ������$n��$l�к���ȥ",
                "force":                30,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������Σ���ȭ��ֱȭ������$n��$l����",
                "force":                30,
                "parry":                10,
                "damage_type":  "����"
        ]),

        ([      "action":               "$N����һ������ȭ��������ȭʹ��������ֱȭ������$n$l",
                "force":                30,
                "parry":                20,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("��Ұ��ȭ������֡�\n");
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
        if( (int)me->query("kee") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("kee", 30);
        return 1;
}
int effective_level() { return 6;}

string *parry_msg = ({
        "$n����Ϊ����һ�С�����ȭ�����ͻ�$N��$w������\n",
});

string *unarmed_parry_msg = ({
        "$n��ȭ���£���ȭ�Ա���һ�С���ȭ������$N���ڳ��⡣\n",


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
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{

        return 0;
}

string perform_action_file(string action)
{
return CLASS_D("fengyunbieshu") + "/yeqiuquan/" + action;
     
}