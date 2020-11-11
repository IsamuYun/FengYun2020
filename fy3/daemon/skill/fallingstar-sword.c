// ���Ǻ�����  written by tiandi�� 
// ������������ʷ��Ҳ�Ҳ������˸������ߵ��书���ƣ����������Լ�Ϲ��һ�����֣������ù����Լ�ȡ�ġ�
// ���ߣ�<��>һ����Ҳûָ������ѩ�����������µ���ֻ�����Ǹ��������ˡ�


inherit SKILL;

mapping *action = ({
        ([      "action":               
"����ɲ���ʣ�$n��ͷ��ֻ��һ�����⣬���Ϯ��!$N֮����������һ����ŭ��֮����$N��ʸ־Ҫ��$n�ȴ�ɱ�ڽ���",
                "dodge":                -120,
                "damage":               130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��һ�ˣ���Σ���ң������Ȼ���˵����������Ʋ��䣬���ȵ��������͡���������һ��������$n�ʺ�",
                "dodge":                -120,
                "damage":               130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"һ�������������磬��$n��Ϯ�����������µ���������Ю�����������⣡$N��ȫ������",
                "dodge":                -130,
                "damage":               120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$n������ʱ����Ȼ�������������������������󣬲Ŵ̳�һ��",
                "dodge":                -140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"��������һ����⣬������δ��֮ǰ��$N�����һ��أ���$n���˹�ȥ",
                "dodge":                -240,
                "damage_type":  "����"
        ]),
 
});

int valid_learn(object me)
{
        object ob;

        if ( me->query("gender") != "Ů��")
		  return notify_fail("ֻ��Ů�Ӳ��������Ǻ�������\n");
	  if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("����Ŀǰ��״������û���ʸ����˹���\n");

	 	if ( (int)me->query_skill("moshen-force",1) < 50)
		   return notify_fail("���ħ���������\n");        
	if( (int)me->query("max_force") < 200 )
                return notify_fail("�������������û�а취�����Ǻ�������\n");

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
notify_fail("�����������������û�а취��ϰ���Ǻ�������\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ�����Ǻ�������\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("zhuge") + "/fallingstar-sword/" + action;
}
 
int effective_level() { return 18;}

string *parry_msg = ({
          "���е�ˮ�鶼�����$n�Ľ�����$v��ˮ�鴮�ɵ��ɽ�����ס��$N�Ĺ�����\n",
        "����ɫ�£�$v���������顢������ˮһ��������$N��$w��\n",
 
});

string *unarmed_parry_msg = ({
   "$n���޷��мܣ������ƾ��������㣬�˼����ǣ���Ȼһ�ſڣ�������ҧס�˽��棡\n",
        "��ҡ���ɣ�$n�����仨�������ȥ��\n",
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

