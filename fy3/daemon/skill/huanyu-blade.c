//LMD@FYTX
inherit SKILL;
mapping *action = ({
        ([      "action":               "$N��¶ƽ��Ц�ݣ�ƾ�ջ��£�ʹ��һ�С�б��ϸ�꡹������$w�����ƻð��ֱ��$n��$l��",
                "damage":               70,
                "dodge":                200,
                "parry":                200,    
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹ��һ�С����紵������$w����ɭɭ���⣬ӳ��$n�ۻ����ң��û�ƽ��$n��$l��",
                "damage":               80,
                "dodge" :               100,
                "parry" :               100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N������Σ�$w����һ�С���籩�꡹�ݺݿ���$n��$l",
                "damage":               80,
                "dodge" :               100,
                "parry" :               100,
                "damage_type":  "����"

        ]),
        ([      "action":               "$N����һ�ݣ�һ�С�����˿˿����$w��$n��$lбб�ó�һ��",
                "damage":               40,
                "dodge" :               10,
                "parry" :               10,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$w�ó����쵶�⣬һ�С�������硹��������ɣ�������Ϣ��ת��$n�ı����Ͷ�$n��$l",
                "damage":               90,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��$w�߻��Σ�һ�С�������Ϣ������ס$n����·������ֱ��$n��$l",
                "damage":               30,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nһ�С����ϸ�꡹��$w�ҷ磬���϶��£������㿳��$n��$l",

                "damage":               50,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nһ�С������������$w�����񿳣�����$n�ľ���ս��",
                "damage":               200,
                "dodge" :               -200,
                "parry" :               -100,
                "damage_type":  "����"
        ]),
        
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
                return notify_fail("�������������û�а취�����굶����\n");



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
int effective_level() { return 20;}

string *parry_msg = ({
        "$nʹ��һ�С�ϸ��������������$v���һ�У�ͻȻ���л�ʽ����ס$n��ȫ��\n",
        "$n����$v��̣�ͻȻ��ת��һ�С��ɻ����꡹����סȫ��Ҫ����\n",
        "$nһ�С�����ӭ��������Ӱ��������Ʈ��ԭ�أ�����$v��������һ���Ŀ���$N��$w��\n",
        "$nһ�С�����Ʒơ���������Σ���$N����ʽ������$vȴֱϮ$N֮�ؾȡ�\n",
});


string *unarmed_parry_msg = ({
"$nһ�С���籩�꡹�������е�$v������$N����ʽ��\n",
"$n���ⶪ��������һ�С����է�硹�����е���������$N֮�ؾȡ�\n",
"$n����$v��÷��겻͸��һ�С�����ϸ�꡹���Ƶ�$N���ֳ��С�\n",
"$nһ�С�ϡ�����͡���ȫȻ����$N�Ĺ�����$vֱ��$N��ȥ���Ƶ�$N�����Ա���\n",
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
        return CLASS_D("lou") + "/blade/" + action;
}