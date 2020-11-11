inherit SKILL;
mapping *action = ({
        ([      "action":               "$N��Ĭ�ˣ�ʹ����ĺ���վ����庮�������е�$w��ն$n��$l",
                "damage":               80,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N���е�$w��ͻȻһ�С���������ת���̡���Ϊ���쵶�⣬����$n��$l",
                "damage":               70,
                "dodge" :               150,
                "parry" :               150,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�����ת�����е�$wʹ����ն��ġ��¹���ˮˮ���족�����������$n��$l",
                "damage":               90,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��Ӱ�ζ�����ʽƮ����һ�С��滨��Ӱ�����¡������е�$w����Ϯ$n��$l",
                "damage":               50,
                "dodge" :               200,
                "parry" :               200,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�������⣬ȥ����磬���е�$w��һ���ǳɺ�ɨ$n��$l",
                "damage":               100,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query_skill("force", 1) < 80 )
                return
                notify_fail("����ڹ��ķ�����㣬�޷�ϰ��Բ����ն��\n");
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
                return notify_fail("���������һ�ѵ���������������\n");

        if( (int)me->query("kee") < 40 )
                return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 40);
        return 1;
}
int effective_level() { return 20;}

string *parry_msg = ({
        "$nʹһ�С�������Ӱ�������е�$v����һƬ��Ӱ��סȫ��Ҫ����\n",
});

string *unarmed_parry_msg = ({
        "$nʹ������Ů���¡���$v�������쵶�⣬�����ƻ��������Ρ�\n",
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
        return 5;
}
int black_white_ness()
{
        return 20;
}

string perform_action_file(string action)
{
        return CLASS_D("moon") + "/moon-blade/" + action;
}

