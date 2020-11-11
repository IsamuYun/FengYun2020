// celestrike.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nһʽ�����Ƴ�ᶡ���˫�Ƽ�����һ�ŵ����İ�����������$n��$l",
                "dodge":                -30,
                "parry":                10,
                "force":                200,
                "damage_type":  "����"
        ]),
        ([      "action":               
	"$N��ָ�罣��һʽ���׺���ա�������$n��$l��ȥ",
                "dodge":                -10,
                "parry":                -30,
                "force":                170,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹһʽ���ƶ����롹������΢��������է��է�ϣ��͵ز���$n��$l",
                "dodge":                -30,
                "parry":                10,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫����������������һʽ�����ɴ�䡹���ó�������̵����룬������$n��ȥ",
                "dodge":                10,
                "parry":                -30,
                "force":                260,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��������һ�ݣ�ʹ��һʽ������������˫�Ʋ�£����ֱ����$n��$l��ȥ",
                "dodge":                -20,
                "parry":                -30,
                "force":                240,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ�䣬ʹһʽ���ޱ���ľ����˫�ƴ�����ɲ�ľ������͵ػ���$n��$l",
                "dodge":                -70,
                "parry":                -10,
                "force":                280,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹһʽ����ɽ��ˮ�����������أ�������ӯ��ͬʱ��$n��$l��ȥ",
                "parry":                -40,
                "force":                320,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("����Ԫ�Ʒ�������֡�\n");
        if( (int)me->query_skill("xizia-shengong", 1) < 20 )
                return 
notify_fail("�����ϼ�񹦻���㣬�޷�����а�Ʒ���\n");
        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������̫�����޷�����Ԫ�Ʒ���\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n����Ϊ����һ�С���Ѫ��ָ��������$N����$w���֡�\n",
        "$n˫�ƽ���ʹ��һ�С�ͯ�Ӱ��١�����ž����һ����$N��$w����˫��֮�䡣\n",
        "$n��һת��һ�С���������������$N����$w���֡�\n",
        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n�������ǣ�һ�С�����Ϊ��������ĳ�ʮ���ƣ��Ƶ�$N�����Ա���\n",
        "$n����Ϊָ��һ�С���ָ˫�ɡ�����$N������ҪѨ��\n",
        "$nʩչ������ָ˫�ɡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
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
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return -10;
}
string perform_action_file(string action)
{
	 return CLASS_D("huashan") + "/hunyuan-zhang/" + action;
}

