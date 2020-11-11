// TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$Nʹ��һ�С����߳��ա��������ڿն�������$w�Ҷ���������$n��$l�ݺ���ȥ��",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]), 
        ([      "action":               
"$Nʹ��һ�С��������֡�������$w�������ѩ�����������֣���������$n��$l��",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ��һ�С���·ɵء�����������$w������ֱָ$n��$l��",
                "damage":               80,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�ն���������������Х����һ�С���Х��������ֱ��$n��$l��ȥ��",
                "damage":               200,
                "dodge":                -110,
                "parry":                -40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ�Σ�����ȻΪ˫��һ�С�����˫�������ֱ�Ϯ��$n������Ҫ����",
                "damage":               10,
                "dodge":                100,
                "parry":                200,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������ת������$wһ�С�����������������$n��$lɨȥ��",
                "damage":               20,
                "dodge":                10,
                "parry":                20,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���δ�������$wһ�С�����ɫ˿����ֱ��ֱ�µش���$n��$l��",
                "damage":               100,
                "dodge":                -10,
                "parry":                20,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ�٣�����$wб��һ�С����߳�����������$n��$l��",
                "damage":               50,
                "dodge":                10,
                "parry":                20,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�趯�����������Ӱ��һ�С����ֵ�Ϻ�����Ӹ����Ƕ�ͬʱ����$n��$l��",
                "damage":               50,
                "dodge":                200,
                "parry":                200,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С�������ɽ������Ծ������$w���϶��£���������$n��$l��",
                "damage":               90,
                "dodge":                30,
                "parry":                50,
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
notify_fail("���������һ��ľ�Ȼ��������Ƶ�������������������\n");

        if( (int)me->query("kee") < 30 )
                return 
notify_fail("����������������Ź�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$nʹ��һ�С�®ɽ��������$v�ڿ�������$N��$w��\n",
	"$n����$v��ڣ�һ�С�������צ����������$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n����������ˣ�����$v�ն�����ס��$N�Ĺ��ơ�\n",
	"$n����ֱͦͦ�˵��ڵأ�����$v����ɨ��$N��\n",
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
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("quanli") + "/yinshe-stick/" + action;
}

