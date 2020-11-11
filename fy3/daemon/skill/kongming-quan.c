// kongming.c

inherit SKILL;

mapping *action = ({
    ([  "action":       "$Nʹһ�С�����ס�ˡ���˫����ƮƮ�ع���$n$l",
        "dodge": 130,
        "parry": 120,
        "force": 180,
        "damage_type": "����"
        ]),
    ([  "action":       "$N����һƽ,����һ��,һ�С�����ʢ����ֱ��$n��$l",
        "dodge": -120,
        "parry": 120,
        "force": 320,
        "damage_type": "����"
    ]),
    ([  "action":       "$N������$nһת��˫������,һ�С��ղ�װˮ������$n$l",
        "dodge":  125,
        "parry":  120,
        "force": 260,
        "damage_type": "����"
        ]),
    ([  "action":       "$N����һ��,����һ��,һ�С��黳���ȡ�����$n��$l",
        "dodge": -120,
        "parry":  0,
        "force": 400,
        "damage_type": "����"
        ]),
    ([  "action":       "$Nʹһ�С���ɽ�����$n��$l��Χ��$N��������Ӱ֮��",
        "dodge": -120,
        "parry":  110,
        "force": 540,
        "damage_type": "����"
    ]),
    ([  "action":       "$N��ɫһ����ʹ�������Ŀ�������Χ��$n��$l��������",
        "dodge":  140,
        "force": 600,
        "damage_type": "����"
    ]),
});

int valid_enable(string usage) { return usage=="unarmed"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ȭ������֡�\n");
        if ((int)me->query("max_force") < 100)
        return notify_fail("�������̫�����޷�������ȭ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 40)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 10)
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

int effective_level() { return 30;}

int learn_bonus()
{
        return -220;
}

int practice_bonus()
{
        return -220;
}

int black_white_ness()
{
        return 50;
 }

string perform_action_file(string action)
{
        return CLASS_D("linjiabao") + "/kongming-quan/" + action;
}
