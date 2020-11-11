inherit SKILL;
mapping *action = ({
([      "action" : "$N˫�ƽ���,һ�С����项��������̽�����ƾ�������$n��ͷ��",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "����"
        ]),
([      "action" : "$N���������һ�С����⡹���Ʒ���ϸ�����$n��$lɨȥ",
                "dodge":                10,
                "parry":                30,
                "damage":                50,
                "damage_type":  "����"
        ]),
([      "action" : "$Nһ�С����᡹��˫�ƻû�ΪһƬ��Ӱ����$n�����ڻ�Ӱ֮�ڡ�",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "����"
        ]),
([      "action" : "$N������շ���һ�С��޺ۡ�����$n��$l��������",
                "dodge":                10,
                "parry":                30,
                "damage":                70,
                "damage_type":  "����"
        ]),
([      "action" : "$N�������ᣬһ�С���������ֻ��˫�ƹ�������бб����$n",
                "dodge":                20,
                "parry":                30,
                "damage":                60,
                "damage_type":  "����"
        ]),
});

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int valid_learn(object me)
{
    if ( me->query("gender") != "Ů��")
       return notify_fail("�����ƴ���������ϰ!\n");
        if ((int)me->query("max_force") < 500)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("mingyu-shengong", 1) < 150)
                return notify_fail("��������񹦻��̫ǳ��\n");
        return 1;
}
int effective_level() { return 25;}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
int practice_skill(object me)
{
        if ((int)me->query_skill("mingyu-shengong", 1) < 250)
                return notify_fail("��������񹦻��̫ǳ��\n");
        if ((int)me->query("kee") < 300)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 400)
                return notify_fail("������������������ơ�\n");
        me->receive_damage("kee", 300);
        me->add("force", -100);
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("yihua") + "/jueqing-zhang/" + action;
}
int learn_bonus()
{
        return 300;
}
int practice_bonus()
{
        return -300;
}
int black_white_ness()
{
        return 820;
}

