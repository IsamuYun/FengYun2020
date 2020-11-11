// ����ָ written by tiandi

inherit SKILL;

mapping *action = ({
	([	"action":		"$N��������һָ�������һ�����й�ֱ����ָδ����ָ���Ѱ�$nѹ�ô���������",
		"dodge":		-70,
		"parry":		80,
		"damage_type":	"����"
	]),
	([	"action":		"$N���β����������������ǰ�մ��״��$n��һ��ԥ��$N����ָָ��������$n��$l",
		"dodge":		-30,
		"force":		200,
		"damage_type":	"����"
	]),
	([	"action":		"ֻ��$Nһת��һָ��в�´�������$n��δ����֮ʱ������$n��$l",
		"dodge":		-30,
		"parry":		150,
		"damage_type":	"����"
	]),
	([	"action":		"$N˫��һ��ʮָ�紩������һ�����·��ɡ�$nֻ����ȫ����$Nָ������֮��",
		"dodge":		-100,
		"parry":		250,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("������ָ������֡�\n");
	
	if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("����Ŀǰ��״������û���ʸ�������ָ��\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("����Ŀǰ��״������û���ʸ�������ָ��\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 17;}

string *parry_msg = ({
        "$nһ�С���ָ���졹���ͻ�$N��$w���Ƶ�$N��;�������е�$w��\n",
        "$n��ȭ��ϣ���ָһ�С����ա�����շ�����ָ���Ƶ�$N����������\n",
});

string *unarmed_parry_msg = ({
        "$n����������һ�С���ңԡѪ������$N֮�ؾȡ�\n",
        "$nʮָ���䣬һ������һ����$Nֻ������������������ƣ���ʧ����Ӱ���١�\n",

});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
        return CLASS_D("zhuge") + "/sushi-zhi/" + action;
}

int learn_bonus()
{
	return 50;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 0;
}

