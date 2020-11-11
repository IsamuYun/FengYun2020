inherit SKILL;
mapping *action = ({
  ([    "action":               "$N����������$w���˼�����Բ��������һ����$n��ͷ����",
    "dodge":            65,
    "parry":            -55,
    "damage":           285,
    "damage_type":      "����"
  ]),
  ([    "action":               "ֻ��$Nһ���߽У��������־��ܣ����е�$wһ�ʣ�ɨ��$n$l",
    "dodge":            50,
    "parry":            -65,
    "damage":           265,
    "damage_type":      "����"
  ]),
  ([    "action":               "$Nʹ��һ�С�Ⱥħ���ס������е�$w������ɳ��ʯ����ȷ�ѹ��$n��$l",
    "dodge":            55,
    "parry":            -55,
    "damage":           280,
    "damage_type":      "����"
  ]),
  ([    "action":               "ֻ��$N����һ�ˣ�����һ���粽��$w����һ���������$n$l",
    "dodge":            55,
    "parry":            50,
    "damage":           270,
    "damage_type":      "����"
  ]),
  ([    "action":               "$N���$w��������������Ȼ��ֻ����ͷһ�������߰�����$n��$l",
    "dodge":            -55,
    "parry":            50,
    "damage":           165,
    "damage_type":      "����"
  ]),
  ([    "action":               "$N��$w����һ������;ȴʹ�˸��ɾ�����βಣ���һ��������$n$l",
    "dodge":            -65,
    "parry":            -60,
    "damage":           275,
    "damage_type":      "����"
  ]),
});

int valid_learn(object me)
{
    object ob;

    if( (int)me->query("max_force") < 100 )
        return notify_fail("�������������û�а취ѧ��ħ�ȡ�\n");
    if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff" )
        return notify_fail("���������һ�����Ȳ���ѧ��ħ�ȡ�\n");

    return 1;
}

int valid_enable(string usage)
{
    return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

string *parry_msg = ({
  "���$n�����е�$v����$N��$w��\n",
});

string *unarmed_parry_msg = ({
  "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
});

string query_parry_msg(object weapon)
{
    if( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int effective_level() { return 28;}

int practice_skill(object me)
{
    if( (int)me->query("kee") < 50 || (int)me->query("force") < 20 )
        return notify_fail("������̫���ˣ�ǿ�����档\n");
    me->receive_damage("kee", 30);
    me->add("force", -5);
    write("�㰴����ѧ����һ���ħ�ȡ�\n");
    return 1;
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
    return 40;
}

string perform_action_file(string action)
{
    return CLASS_D("linjiabao") + "/fumo-zhang/" + action;
}
