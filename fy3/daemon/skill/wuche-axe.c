// TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N����$w�տ���Ю�ź���������һ�С�����ÿÿ����ֱȡ$n�ĸ���Ҫ����",
                "damage":               200,
                "dodge":                -540,
                "parry":                -500,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$w�����Х��һ�С����ֳ��ա��������$n$l��ȥ��",
                "damage":               150,
                "dodge":                -600,
                "parry":                -600,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w������������һ�С�ԨԴ������������㿳��$n$l��",
                "damage":               250,
                "dodge":                -510,
                "parry":                -540,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С����ɳ��ڡ�������$w�趯�����渫�ƣ�����һ���̳�����������$n��$l��",
                "damage":               210,
                "dodge":                -410,
                "parry":                -440,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 15 )
                return 
notify_fail("���������������Ҳ�����һ����������ǿ������\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="axe") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "axe" )
                return 
	notify_fail("���������һ�Ѹ�ͷ���������Ƶ�������������������\n");
        if( (int)me->query("kee") < 60 )
        return 
	notify_fail("����������������Ÿ�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 60);
        return 1;
}
int effective_level() { return 25;}
 
string *parry_msg = ({
        "���$nһ�С�������į�����Ӷ�����$v����$N��$w��\n",
        "���$n����$vһ�֣�һ�С���ħ��𡹣�б��$N��$w��\n",
        "���$n����$v�ն���ɣ�һ�С��鲨���������$N��$w��\n",
        "���$n����$v������ת��һ�С�������ۡ�����ɨ$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n���е�$v�趯��ɣ�һ�С�������ҡ������ס��$N�Ĺ��ơ�\n",
        "$n��Ӱ�ζ���һ�С�ǧ̶���ʡ�������$N�����̡�\n",
        "$n����һ����һ�С�������������$N�Ĺ��ơ�\n",
        "$n���е�$v���϶��£�һ�С�ʼ�����ء�������$N��Ҫ����\n",
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
        return CLASS_D("shaolin") + "/wuche-axe/" + action;
}

