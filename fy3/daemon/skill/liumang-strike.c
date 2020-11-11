// TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l��",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]), 
        ([      "action":               
"$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l��",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������������֣�һ�С�������������ץ��$n��$l��",
                "damage":               80,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��Ю��һ���ȳ�֮������$n��$l��",
                "damage":               200,
                "dodge":                -110,
                "parry":                -40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������ɽ��һʽ�����������˫ȭ���ƶ���������$n��$l��",
                "damage":               10,
                "dodge":                100,
                "parry":                200,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������أ�����������һʽ��ľ�ѳ��ۡ���������$n�Ƴ���",
                "damage":               20,
                "dodge":                10,
                "parry":                20,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������飬����������ޣ�һʽ��ˮ�����¡�����$n�޿ɶ���",
                "damage":               100,
                "dodge":                -10,
                "parry":                20,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),


});

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	return notify_fail("����å��ȭ������֡�\n");
if ((int)me->query_skill("wuchenforce", 1) < 20)
		return notify_fail("����޳��ķ���򲻹����޷�����å��ȭ��\n");
if( (int)me->query("str") + (int)me->query("max_force") / 100 < 35 )
                return 
notify_fail("���������������Ҳ�����һ����������ǿ������\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}

mapping query_action(object me)
{
        if (random(me->query_skill("unarmed")) > 100 &&
            me->query_skill("wuchenforce") > 70 &&
            me->query("force") > 100 ) {
                me->add("force", -100);
                return ([
                "action": "$Nһ������Ծ�����ɣ����ֻ�Բ�����ֻ������ۼ�ȫ�����������$n",
                "force": 500,
                "damage_type": "����"]);
        }
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
         if( (int)me->query("kee") < 30 )
                return 
notify_fail("�����������������ȭ������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$nһʽ���һ�׶����˫�������»���ȭ�����棬����$N�ı�����\n",
	"$n�ڿշ���һʽ���˷��꡹��˫��˫�����,������$N�ı�����\n",
});

string *unarmed_parry_msg = ({
 "$nһʽ���һ�׶����˫�������»���ȭ�����棬����$N�ı�����\n",
	"$n�ڿշ���һʽ���˷��꡹��˫��˫�����,������$N�ı�����\n",
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
        return -1000;
}
int practice_bonus()
{
        return -1000;
}
int black_white_ness()
{
        return 600;
}

string perform_action_file(string action)
{
        return CLASS_D("quanli") + "/liumang-strike/" + action;
}

