inherit SKILL;

mapping *action = ({
([      "action":"$Nʹһʽ��������ơ�������$w����΢�񣬻ó�һ�����������$n��$l",
        "force" : 30,
        "dodge" : 10,
        "damage": 100,
        "lvl" : 0,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N�Ʋ���ǰ��ʹ�����껨�׷ɡ�������Χ�ƣ�$w��������$n��$l��ȥ",
        "force" : 40,
        "dodge" : 10,
        "damage": 150,
        "lvl" : 9,
        "skill_name" : "�껨�׷�",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ�������䡹������Ʈ�����ߣ��˷�����������$wңң����$n��$l",
        "force" : 60,
        "dodge" : 50,
        "damage" : 200,
        "lvl" : 18,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action":"$N��������Ծ��һʽ���ϻ����衹�����⻯Ϊ��ɫ��Ʈ��$n��$l",
        "force" : 80,
        "dodge" : 90,
        "damage": 250,
        "lvl" : 27,
        "skill_name" : "�ϻ�����",
        "damage_type":  "����"
]),
([      "action":"$N����$w�й�ֱ����һʽ��������л����������Ϣ�ض�׼$n��$l�̳�һ��",
        "force" : 100,
        "dodge" : 120,
        "damage": 300,
        "lvl" : 36,
        "skill_name" : "������л",
        "damage_type":  "����"
]),
([      "action":"$N����$wбָ���죬��â���£�һʽ���ɻ���Ҷ������׼$n��$lбб����",
        "force" : 110,
        "dodge" : 150,
        "damage": 350,
        "lvl" : 44,
        "skill_name" : "�ɻ���Ҷ",
        "damage_type":  "����"
]),
([      "action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ�����ش�ء�����$n��$l",
        "force" : 120,
        "dodge" : 200,
        "damage": 400,
        "lvl" : 52,
        "skill_name" : "���ش��",
        "damage_type":  "����"
]),
([      "action":"������,ֻ�����굽������,ͻȻ�����������$n,$n��ʱ��Ѫֱ��",
        "force" : 180,
        "dodge" : 250,
        "damage": 900,
        "lvl" : 150,
        "skill_name" : "�Ʒ������Ʒ���",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
    if ( me->query("gender") != "Ů��")
       return notify_fail("�ഫ�Ʒ罣����Ů�����,����������ϰ!\n");
        if ((int)me->query("max_force") < 500)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("mingyu-shengong", 1) < 50)
                return notify_fail("��������񹦻��̫ǳ��\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}


int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query_skill("mingyu-shengong", 1) < 420)
                return notify_fail("��������񹦻��̫ǳ��\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("��������������Ʒ罣����\n");
        me->receive_damage("qi", 25);
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("yihua") + "/yifeng-jian/" + action;
}

