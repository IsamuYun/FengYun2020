//by lion

inherit SKILL;

mapping *action = ({
        ([      "action":
"$Nʹһ�С�ӭ����������������$w��������$n���ţ���ɤ��ǰ��",
                "damage":               350,
                "dodge":                500,
                "parry":                600,
                "force" :               300,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���㾫�񣬶���$w��һ�С�����Ѱ�ߡ�����$n$l",
                "damage":               320,
                "dodge":                600,
                "parry":                300,
                "force" :               350,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ���粽��ʹһ�С���ɽ��ˮ��������$w�������ٴ���$n��$l",
                "damage":               255,
                "dodge":                520,
                "parry":                345,
                "force":                200,
                "damage_type":  "����"
        ]),
         ([      "action":
"$Nһ��ǹ�ѣ�ž����һ���������ǹ�����������ң�����ʵʵ����$nȫ��Ҫ��",
                "damage":               225,
                "dodge":                600,
                "parry":                500,
                "force" :               450,
                "damage_type":  "����"
        ]),
         ([      "action":
"ֻ��$Nһ��б�磬ʹ�����ٻ������ơ�������$w����һ�����������¶��ϼ���$n$l",
                "damage":               235,
                "dodge":                200,
                "parry":                80,
                "force":                600,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N����һ��������$w�����벻���ĽǶȴ���$n��$l��\n��һ�С����߳������������磬�����ޱ�",
                "damage":               445,
                "dodge":                500,
                "parry":                400,
                "force":                300,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��������Ͷ���ơ�������б�ɣ��Ӳ���ͻ��һǹ������$n$l",
                "damage":               240,
                "dodge":                150,
                "parry":                60,
                "force" :               250,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�������ߣ����Ǻ���һ��ת����æ��ʹ��һ�С�����ǹ����$wһͦ����$n$l",
                "damage":               1130,
                "dodge":                100,
                "parry":                200,
                "force" :               1200,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_force") < 300 )
                return notify_fail("�������������û�а취������ǹ����\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("���������һ��ǹ������ǹ����\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}

string *parry_msg = ({
        "$nʹ��һ�С�����ָ·�������е�$v����$N��$w��\n",
        "$nʹ������ɨǧ��������$N��$w�������⡣\n",
        "$nʹ��һ�С����ĺδ��������е�$v����������գ�������$N��$w��\n",
        "$n���е�$vһ����һ�С�������;������$N��$w�������ȥ��\n",
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string query_parry_msg(object weapon)
{
                return parry_msg[random(sizeof(parry_msg))];
 }

int effective_level() { return 15;}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return
notify_fail("���������һ����ǹ���������Ƶ�������������ǹ����\n");
        if( (int)me->query("kee") < 50 
        ||    (int)me->query("force") < 30  )
                return
notify_fail("�����������������ǹ������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 50);
        me->add("force", -30);
        write("�㰴����ѧ����һ�����ǹ����\n");
        return 1;
}

int learn_bonus()
{
        return -300;
}
int practice_bonus()
{
        return -200;
}
int black_white_ness()
{
        return 82;
}
string perform_action_file(string action)
{
        return CLASS_D("linjiabao") + "/bawang-qiang/" + action;
}
