inherit SKILL;

mapping *action = ({
        ([      "action":               "$N�Ĺ����߶�ʮһ������$w����$n��ͷ����һ�һ�",
                "force":               700,
                "dodge":                600,
                "parry":                200,
                "damage_type":  "����"
        ]),
        ([      "action":               "ֻ��$N��ð�׹⣬���͹�𣬳���$w�ͳ�$n��$l����ɨ�˹�ȥ",
               "damage":               550,
                "dodge":                400,
                "parry":                400,
                "damage_type":  "����"
                ]),
        ([      "action":               "ֻ���䣡��һ��$N��$w�ڵ����ҵó������������$N���Ʒ��˸���ͷ������һ����$n���˹�ȥ",
                "damage":               570,
                "force" :               500,
                "dodge":                500,
                "parry":                700,
                "damage_type":  "����"
        ]),
        ([      "action":               "ֻ��$N��һ���������е�$w��������ɨ��Ȧ���Ƶ�$n���˲���",
                "damage":               540,
                "force" :               400,
                "dodge":                100,
                "parry":                400,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹ����һ�С��嶡��ɽ�������е�$w�������ᣬ�����転����$n$l������ȥ",
                "force":               300,
                "damage" :              350,
                "dodge":                100,
                "parry":                400,
                "damage_type":  "����"
        ]),
        ([      "action":               "����$Nһ��ת������$w���¶���һ����$nֻ��һ���������������\n$n���ڰ��н���֮ʱ��$N��$w����һת�������˻���",
                "dodge":                150,
                "parry":                500,
                "damage":               525,
                "force" :               600,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("str") < 40 )
                return notify_fail("��ɽ��Ҫ�㹻�ı������ܷ������á�\n");
        if( (int)me->query("max_force") < 500 )
                return notify_fail("�������������û�а취ѧ��ɽ����\n");
        if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "hammer" )
                return notify_fail("���������һ�Ѵ��Ӳ���ѧ��ɽ����\n");

        return 1;
}

int valid_enable(string usage)
{
 return (usage=="hammer") || (usage=="parry");
}

int effective_level() { return 32;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string *parry_msg = ({
        "$n����һ����һ�У۵����س������е�$v�͵�����$N��$w��\n",
        "$n����΢�٣����е�$vһ�У�Χ�����ԣݷ���$N�ıؾ�֮����\n",
        "$n���е�$v�������ϼ��ӣ�һ�У۶�����ݿĿ���$N���е�$w\n",
});

string *unarmed_parry_msg = ({
        "$nһ�У��ӹ������ݣ����е�$v��ƫ�����$N��̫����Ѩ��\n",
        "$n���е�$v�����ң�һ�Уۺ�ɨǧ���ݷ�ס��$N�Ĺ��ơ�\n",
        "$n�����������һ�У���ɳ�������е�$v����$N�ĺ��ԣ��Ƶ�$N��;���С�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 60 || (int)me->query("force") < 60 )
                return notify_fail("������̫���ˣ�ǿ�����档\n");
        me->receive_damage("kee", 60);
        me->add("force", -60);
        write("�㰴����ѧ����һ�鿪ɽ����\n");
        return 1;
}

int learn_bonus()
{
        return -100;
}
int practice_bonus()
{
        return -100;
}
int black_white_ness()
{
        return 10;
}
string perform_action_file(string action)
{
        return CLASS_D("linjiabao") + "/kaishan-chui/" + action;
}
