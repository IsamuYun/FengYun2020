// liuxing-hammer.c
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N����$w�ն���ɣ��������಻�ϣ�һ�У������˵��ݣ��������$n��к��ȥ��",
                "force":               70,
                "dodge":                100,
                "parry":                100,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������ɣ���Ӱ�������֣�һ�У۽�󸱼�£ݣ����е�$wȴ�絽$n����ǰ��",
                "damage":               70,
                "dodge":                20,
                "parry":                60,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               

"$N����$w�趯��һ�У����������Ю�������ײ��֮��������$n��$l��",

                "damage":               70,
                "force" :               200,
                "dodge":                -100,
                "parry":                200,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���е�$wһת��һ�У���뵾��ݴ�����˷�����$n��$l",
                "damage":               40,
                "force" :               200,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ�����е�$w��һ�У�󸷭�ǰףݴ�Ӱ������裬����ʵʵ�Ļ���$n��$l",

                "force":               100,
                "damage" :              50,
                "dodge":                100,
                "parry":                400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 25 )
                return 
notify_fail("���������������Ҳ�����һ����������ǿ������\n");

        return 1;
}

int valid_enable(string usage)
{

        return (usage=="hammer") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "hammer" )
                return 
notify_fail("���������һ�������������Ƶ���������������󸴸����\n");

        if( (int)me->query("kee") < 60 )
                return 
notify_fail("���������������󸴸������������Ϣ��Ϣ�ɡ�\n");

        me->receive_damage("kee", 60);
        return 1;
}
int effective_level() { return 15;}
 
string *parry_msg = ({
        "$n����һ����һ�У۳�����Ծ�����е�$v�͵�����$N��$w��\n",
        "$n����΢�٣����е�$vһ�У�����ڹȣݷ���$N�ıؾ�֮����\n",
        "$n���е�$v�������ϼ��ӣ�һ�Уۻ��ܶ����ݿĿ���$N���е�$w\n",
});

string *unarmed_parry_msg = ({
        "$nһ�Уۣݣ����е�$v��ƫ�����$N��̫����Ѩ��\n",
        "$n���е�$v�����ң�һ�У����׷�£ݷ�ס��$N�Ĺ��ơ�\n",
        "$n�����������һ�У۽������������е�$v����$N�ĺ��ԣ��Ƶ�$N��;���С�\n",
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
        return -10;
}
int black_white_ness()
{
        return 10;
}
string perform_action_file(string action)
{
        return CLASS_D("wudujiao") + "/hammer/" + action;

}
