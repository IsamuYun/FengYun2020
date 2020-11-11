// liuh-ken.c

inherit SKILL;

mapping *action = ({
        ([      "action":               "$N��ɷ��˫�ۻ���ǧ���⻪��һ�С��������ࡹ��׼$n��$l����ǵص�Ϯ��",
                "force":                40,
                "parry":                20,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N���в�����΢̧��ۣ�˫�Ʒ��ɣ�һ�С��Ļ�ƬƬ����������$n��$l",
                "force":                30,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��շ���������Σ�����һ�С����ɪɪ�������д�ʵ��ʵ�д��飬����Ľ�$n��������",
                "force":                30,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����һ������������������ʹ������ѩ���ϡ����Ʒ�����ޱȺ��⣬��и�ɻ��Ļ���$n$l",
                "force":                30,
                "parry":                20,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("���ļ��Ʒ�������֡�\n");
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
int effective_level() { return 10;}

string *parry_msg = ({
        "$n����Ϊ����һ�С����ⰺȻ�����ͻ�$N��$w������\n",
});

string *unarmed_parry_msg = ({
        "$n��ȭ���£���ȭ�Ա���һ�С���ѩӭ��������$N���ڳ��⡣\n",

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
        return CLASS_D("baihua") + "/quan/" + action;
}