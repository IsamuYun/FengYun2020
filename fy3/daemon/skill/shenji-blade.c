//TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               "$N���ϸ��ֳ�һ˿�����Ц�ݣ�ͻȻʹ��һ�С�Ц��ص���������$wֱ��$n��$l��",
                "damage":               170,
                "dodge":                -200,
                "parry":                -200,   
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹ��һ�С��û��١�����$w�����������⣬ӳ��$n�ۻ����ң��û�ƽ��$n��$l��",
                "damage":               180,
                "dodge" :               -100,
                "parry" :               -100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������Σ�$w����һ�С������������ݺݿ���$n��$l",
                "damage":               180,
                "dodge" :               -100,
                "parry" :               -100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����һ����һ�С����׳�н����$w��$n��$lбб�ó�һ��",
                "damage":               140,
                "dodge" :               -100,
                "parry" :               -100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$w�ó����쵶�⣬һ�С���ˮ���㡹��������ɣ�������Ϣ��ת��$n�ı����Ͷ�$n��$l",
                "damage":               190,
                "dodge" :               -200,
                "parry" :               -100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��$w�߻��Σ�һ�С����Ŵ򹷡�����ס$n����·������ֱ��$n��$l",
                "damage":               230,
                "dodge" :               -200,
                "parry" :               -100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nһ�С�������������$w�ҷ磬���϶��£������㿳��$n��$l",
                "damage":               250,
                "dodge" :               -200,
                "parry" :               -100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nһ�С���ݾ��ߡ���$w�����񿳣�����$n�ľ���ս��",
                "damage":               200,
                "dodge" :               -200,
                "parry" :               -100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹ��һ�С�˳��ǣ�򡹣�$w������������$n����һ����б����˳��һ��",
                "damage":               150,
                "dodge" :               -100,
                "parry" :               -100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����һ��������$w�󿪴�ϣ�һ�С�Զ������������Բ���������磬��$n����Χס",
                "damage":               280,
                "dodge" :               -180,
                "parry" :               -180,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$wһ�С���;��뽡������˺�һ����ɱ��ȥ��ͻȻ����һ��������$n��$l",
                "damage":               200,
                "dodge" :               -200,
                "parry" :               -100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nһ�С��赶ɱ�ˡ������������һ������$n��$l",
                "damage":               310,
                "dodge" :               -200,
                "parry" :               -100,
                "damage_type":  "����"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
                return notify_fail("�������������û�а취�����������\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�������������\n");
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
int effective_level() { return 22;}

string *parry_msg = ({
        "$nʹ��һ�С�͵��������������$v���һ�У�ͻȻ���л�ʽ����ס$n��ȫ��\n",
        "$n����$v��̣���;ͻȻ��ת��һ�С�ָɣ�������סȫ��Ҫ����\n",
        "$nһ�С���ʬ���꡹����Ӱ��������Ʈ��ԭ�أ�����$v��������һ���Ŀ���$N��$w��\n",
        "$nһ�С�������ɽ����������Σ���$N����ʽ������$vȴֱϮ$N֮�ؾȡ�\n",
});

string *unarmed_parry_msg = ({
"$nһ�С�����Ϊ�����������е�$v������$N����ʽ��\n",
"$n���ⶪ��������һ�С���ש���񡹣����е���������$N֮�ؾȡ�\n",
"$n����$v��÷��겻͸��һ�С�������������Ƶ�$N���ֳ��С�\n",
"$nһ�С�Χκ���ԡ���ȫȻ����$N�Ĺ�����$vֱ��$N��ȥ���Ƶ�$N�����Ա���\n",
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
        return -150;
}
int practice_bonus()
{
        return -150;
}
int black_white_ness()
{
        return 30;
}

string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/shenji-blade/" + action;
}


