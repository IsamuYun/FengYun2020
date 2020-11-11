// ���齣�� written by tiandi�� 

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N����Ƭ�����У���Ȼһ������ĺ����ѣ��ɡ�Ʈ���㡢�䣬�����޾�",
                "dodge":                -120,
                "damage":               130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"����������ʱһ�䣬�漴��б��һ�㣬�ѵ��˵��ϣ������־�ס��$n",
                "dodge":                -20,
                "damage":               130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$w�����Ĺ�â��һɲ���ʸǹ���$n˫Ŀ������",
                "dodge":                -130,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�ӽ��������̳�ǧ�ٵ�������ȴֻ�̳�һ����",
                "dodge":                -140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��һ�｣�������̳�һ����ȴ��ǧ�ٵ�����",
                "dodge":                -140,
                "damage_type":  "����"
        ]),
 
});

int valid_learn(object me)
{
        object ob;
	if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("����Ŀǰ��״������û���ʸ������齣����\n");

	 if( (int)me->query_skill("youling-force",1) < 100 )
                return notify_fail("�������������û�а취�����齣����\n");
	 
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���أ�\n");

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
notify_fail("�����������������û�а취��ϰ���齣��\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ���������齣��\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("zhuge") + "/youling-sword/" + action;
}
 
int effective_level() { return 18;}

string *parry_msg = ({
        "$nŲ���ƣ������ܣ��㿪��$N��$w��\n",
        "$nʹ��һ�С�ǧ����á������е�$v����������գ�������$N��$w��\n",
});

string *unarmed_parry_msg = ({
       "$nͻȻ������ɣ�������ס��̫�������˺ڵ����塣\n",
        "ֻ����ǰ��Ӱһ��������ٿƮ��$n�Ѵ���$N��\n",

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
	return 15;
}

