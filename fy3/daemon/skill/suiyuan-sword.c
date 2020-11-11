//TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N����������$w����������һ�С������⡹��$n��������һƬ����֮��",
		"force" :		50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ����Ե���ǽ����еġ��������ݡ�������$w�Ʋ��ɵ���ֱȡ$n��$l",
                "force":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�һ�߹�ǣ�����ڿն�������Ϊһ�壬����һ������ֱ��$n��$l",
                "force":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w������������ʵ��䣬һʽ��������������������$n��$l�̳�",
                "force":                90,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wԲת��������ɭ��һ�С�̶��ӰԲ������$n��$l",
                "force":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�����ҿ������һ�С����ɱ��ġ����ֶ�׼$n$lһ����ȥ",
                "force":               50,
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
notify_fail("�����������������û�а취��ϰ��Ե���ǽ�����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ����Ե���ǽ�����\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/suiyuan-sword/" + action;
}
 
int effective_level() { return 10;}

string *parry_msg = ({
        "$nʹ��һ�С�̶ˮ���졹�����ΰεض������е�$v������$N��$w��\n",
        "$nʹ����ͥǰ���ѡ�������δ��������$v��$N��$w�������⡣\n",
        "$nʹ��һ�С�ǽ���෼�������е�$v��â������������Զ������������$N��$w��\n",
        "$n���е�$vһ����һ�С�������Ե������$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����$N�Ų����ģ�һ�С����˸��ԡ���ס��$N�Ĺ��ơ�\n",
        "$n΢һ����һ�С�����ǿǣ������������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С����鲻ʶ����$vֱ��$N��˫�֡�\n",
        "$n�����е�$vһ����һ�С�Ұ�����ˡ����ȵ�$N�������ˡ�\n",
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
	return -10;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 10;
}

