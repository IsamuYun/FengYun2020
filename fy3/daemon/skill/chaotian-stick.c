// �����
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N�����ڿն���ʹ���� �������ء�������$w����������������֮������$n��$l�ݺ���ȥ��",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "damage_type":  "����"
        ]), 
        ([      "action":               
"$Nʹ��һ�С������׷𡹣�����$w�������ѩ���������֣�����$n��$l��",
                "damage":               80,
                "dodge":                20,
                "parry":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ����Ȼ�ӳ���һ��֮�࣬һ�С���ȥ�δӡ����������$w��Ӱ�ӣ�����ֱָ$n��$l��",
                "damage":               80,
                "dodge":                100,
                "parry":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�ն��������ػ����Σ�ֻ������һ��Ƭ�ҳ���һ�С�������������ֱ��$n��$l��ȥ��",
                "damage":               200,
                "dodge":                -110,
                "parry":                -40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���죬ŭ���ɺ磬һ�С��������������ֱ�Ϯ��$n������Ҫ����ʹ$n����ʤ����",
                "damage":               300,
                "dodge":                100,
                "parry":                200,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{	
	object weapon;
        if( (int)me->query("str") < 35 )
                return notify_fail("���������������Ҳ�����һ����������ǿ������\n");
	 if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("����Ŀǰ��״������û���ʸ������Ź���\n");

	
	 if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return notify_fail("���������һ��ľ�Ȼ��������Ƶ�������������������\n");

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

        if(me->query("TASK")<1000||(string)me->query("class")!="zhuge")
		return notify_fail("����Ŀǰ��״������û���ʸ���������\n");
	if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return 
		notify_fail("���������һ��ľ�Ȼ��������Ƶ�������������������\n");

        if( (int)me->query("kee") < 60 )
                return 
		notify_fail("����������������Ź�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 60);
        return 1;
}
int effective_level() { return 22;}
 
string *parry_msg = ({
        "$nʹ��һ�С��������¡�����$v��$w��ȥ������$N��$w��\n",
	"$n����$vһ�̣�һ�С�����塹��������$N��$w��\n",
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
        return CLASS_D("zhuge") + "/chaotian-stick/" + action;
}

