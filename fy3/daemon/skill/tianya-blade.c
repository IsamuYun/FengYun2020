// �������µ� written by tiandi�� 
/*��������ѩ�Ѱε��� 
����������˫�ĵ�������˼�ǵĵ����� 
�������۶�񶾵İ��������۶ิ�ӵĹ�ƣ���������ѵ��������Ǳ�ѩ���������¡� 
������������һ�������������죬���찵����أ�ÿһ���������������ˣ����Ǵ����м�ϵģ��������ֽ�����С��һ����ͣϸ�ָ�Ҳδ������˾�ȷ�� 
����������ʧ�󣬲ſ���Ѫ��Ѫ�Ǵ��������µ� 
������������� 
����һ�����ڴ���üë��������������Ǽ⣬��һ��ֻҪ����������������ͷ 
�����������ʡ� 
������Ѫ�ӱǼ����䣬�����촽�����������ֿࡣ��������ÿһ�����ⶼ����ʹ����鴤������ȴû�ж�
*/
inherit SKILL;

mapping *action = ({
        ([      "action":               
"������ʱ��$NƮ��ٿ���ģ����ض�Ȼ�������ݵ�б������ҫ�գ�һɲ�Ǽ䣬�����߼�ɱ��",
                "dodge":                -120,
                "damage":               11230,
                "damage_type":  "����"
        ]),
        ([      "action":               
"������ʱ��Ȼ�е���һ���������$N��$w�����ϵ��£���һ�޶��ĵ�",
                "dodge":                -120,
                "damage":               11330,
                "damage_type":  "����"
        ]),
        ([      "action":               
"������̲��ݻ���һ˲�ʣ�$N��$wͻȻ�����´�������������һ�죬$w�ų��𻨣�����$n��$l��",
                "dodge":                -130,
                "damage":               11220,
                "damage_type":  "����"
        ]),
        ([      "action":               
"������һն���������ѡ�$w���������������������ᵶ��ն$n��գ�ۼ���ն�����ߵ�",
                "dodge":                -140,
				 "damage":               11220,
                "damage_type":  "����"
        ]),
        ([      "action":               
"��Ȼ�䣬һƬ���⣬һ��ѪӰ������ֱ��$n��\n��һ�±���ʱҸ���������������Ҿ�������һ�����������岿λ�⣬��ĵط�������",
                "dodge":                -240,
			 "damage":               11220,
                "damage_type":  "����"
        ]),
 
});

int valid_learn(object me)
{
        object ob;
	if ( me->query("gender") != "����")
		return notify_fail("��������еİɡ�\n");
	  if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("����Ŀǰ��״������û���ʸ����˹���\n");
	if ( (int)me->query_skill("moshen-force",1) < 50)
		   return notify_fail("���ħ���������\n");        

	  if( (int)me->query("max_force") < 200 )
                return notify_fail("�������������û�а취���������µ���\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("���أ�\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
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
notify_fail("�����������������û�а취��ϰ�������µ���\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ���������µ���\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("zhuge") + "/tianya-blade/" + action;
}
 
int effective_level() { return 100;}

string *parry_msg = ({
        "$nû�����ܣ�û�ж���������$n�ĵ�����������һ�죬�����ļ���һ������������𣬿����������������Ʋ�������⡣\n",
        "$n�����Ӻ�Ȼбб�ɳ���ǡ�ɴӱ�Ե�ӹ���\n",
});

string *unarmed_parry_msg = ({
        "$nû�����ܣ�û�ж���������$n�ĵ�����������һ�죬�����ļ���һ������������𣬿����������������Ʋ�������⡣\n",
        "$n�����Ӻ�Ȼбб�ɳ���ǡ�ɴӱ�Ե�ӹ���\n",
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
	return -30;
}
int black_white_ness()
{
	return 15;
}
string belong()
{
	return "common";
}