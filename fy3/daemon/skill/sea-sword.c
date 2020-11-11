inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N����������$w����������һ�С�����������$n��������һƬ����֮��",
                "force" :               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ����Ԩ�����еġ��޵н���������$w�Ʋ��ɵ���ֱȡ$n��$l",
                "force":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�ɱ�˽������ڿն�������Ϊһ�壬����һ������ֱ��$n��$l",
                "force":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w������������ʵ��䣬һʽ��������������������$n��$l�̳�",
                "force":                90,

                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�����ҿ������һ�С����ֽ������ֶ�׼$n$lһ����ȥ",
                "force":               90,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;
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
notify_fail("�����������������û�а취��ϰ��Ԩ������\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ�麣Ԩ������\n");
        return 1;
}


string perform_action_file(string action)
{
        return CLASS_D("moondoor") + "/sea-sword/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({
        "$nʹ��һ�С����Ľ��������ΰεض������е�$v������$N��$w��\n",
        "$nʹ�������ƽ���������δ��������$v��$N��$w�������⡣\n",
        "$nʹ��һ�С����ֽ��������е�$v��â������������Զ������������$N��$w��\n",
        "$n���е�$vһ����һ�С����޽�������$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����$N�Ų����ģ�һ�С����Ľ�����ס��$N�Ĺ��ơ�\n",
        "$n΢һ����һ�С����ƽ�������������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С����޽�����$vֱ��$N��˫�֡�\n",
        "$n�����е�$vһ����һ�С����ֽ������ȵ�$N�������ˡ�\n",
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
        return 15;

}