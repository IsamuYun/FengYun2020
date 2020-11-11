inherit SKILL;
mapping *action = ({
        ([      "action":               "$Nʹһ�С�ɱ�˼�Ѫ��������$w��������б����һ������$n��$l��",
                "dodge":                -870,
                "parry":                -700,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N���μ�ת�������˶���$w����һ�С��ȷ�Ѫ�꡹�����������$n��$l��ȥ��",
                "dodge":                -670,
                "parry":                -600,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����Ծ���ն�����$w��һ�С�Ѫ����𡹣��������$n��$l",
                "dodge":                -570,
                "parry":                -500,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$w�趯���������ƣ�һ�С�Ѫ����������������˷�������$nɱȥ��",
                "dodge":                -470,
                "parry":                -400,

                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$w����ƬƬ���⣬һ�С���ë��Ѫ��������һƬ��Ӱ��$n��ȥ",
                "dodge":                -370,
                "parry":                -200,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$w����һƬѪӰ��һ�С���Ѫ���ˡ�ֱ��$n$l",
                "dodge":                -270,
                "parry":                -100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹһ�С�Ѫ��ģ����������$w��ת�������������ն��$n��$l",
                "dodge":                -170,
                "damage_type":  "����"
        ]),
});
int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�������������\n");
        return 1;
}
int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        object weapon;
        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ���������Ѫ���󷨡�\n");
        if( (int)me->query("kee") < 40 )

                return notify_fail("�������������Ѫ���󷨣���������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 40);
        return 1;
}
int effective_level() { return 8;}
string *parry_msg = ({
        "$nʹ��һ�С���Ѫ���ġ������е�$v������������$N��$w��\n",
        "$n����$v�����������⣬����ɭɭ��һ�С�ѪŨ��ˮ�����Ӳ��滮��$N֮�ؾȡ�\n",
        "$n����ת�������е�$v�⻪������һ�С��ʸ���Ѫ��������$N��$w��\n",
});
string *unarmed_parry_msg = ({
"$nʹ��һ�С�Ż����Ѫ�������е�$v��Ȼ������$N�Ĺ����沨��ɢ��\n",
"$n���е�$v���л�ʽ���������ࡣ\n",
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
        return 100;
}
int practice_bonus()
{
        return 50;
}
int black_white_ness()
{
        return 30;
}
string perform_action_file(string action)
{
        return CLASS_D("bloomdoor") + "/bloom-blade/" + action;
}
