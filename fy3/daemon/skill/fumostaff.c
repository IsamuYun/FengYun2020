// TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$Nʹһ�С��������������$w�趯��ɣ�ɨ��$n���̣�",
                "damage":               40,
                "dodge":                40,
                "parry":                -40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w��һ�С���Ŀ������������$wֻ�����أ�����$n$l��",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������$w��ʹ�������Ӻ�ա�������$w���ն��£�����$n$l��",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��ຣ�Ⱥ�����$w�󿪴�ϣ�ײ��$n$l��",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 35 )
                return 
notify_fail("���������������Ҳ�����һ����������ǿ������\n");

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

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return 
notify_fail("���������һ��ľ�Ȼ��������Ƶ��������������ȷ���\n");

        if( (int)me->query("kee") < 60 )
                return 
notify_fail("������������������ȷ�����������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 60);
        return 1;
}
int effective_level() { return 10;}
 
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
        return CLASS_D("shaolin") + "/fumostaff/" + action;
}

