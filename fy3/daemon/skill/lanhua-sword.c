// fonxansword.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹһ�С�������̡�������$w�������$n��$l",
                "dodge":                -20,
                "damage":               230,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ�С��������ơ�����һ���⻡����$n��$l",
                "dodge":                -30,
                "damage":               350,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취������������\n");

        if( (string)me->query_skill_mapped("force")!= "lanhua-force")
                return notify_fail("��������������������ķ���������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("�����������������û�а취��ϰ����������\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ������������\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("yihua") + "/lanhua-sword/" + action;
}
 
int effective_level() { return 18;}

string *parry_msg = ({
        "$nʹ��һ�С��ʵ��ɷɡ������е�$v����һƬ��Ӱ���Ŀ���$N��$w��\n",
        "$nʹ�����⡹�־�����$N��$w�������⡣\n",
        "$nʹ��һ�С�����ϸ�꡹�����е�$v��������ˮ�Σ�������$N��$w��\n",
        "$n���е�$vһ����һ�С����ﳯ��������$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С��������졹����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С�����񡹣�$vֱ��$N��˫�֡�\n",
        "$n�����е�$v���������ɵ����ȵ�$N�������ˡ�\n",
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

