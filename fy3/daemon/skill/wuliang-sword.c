//TIE@FY3
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	
		"action":		"$Nʹһ�С����������������α���������$wһ�ڣ���$n��$l��ȥ",
		"dodge":		40,
		"force":		150,
		"damage_type":	"����"
	]),
	([	
		"action":		"$N���ΰεض�������$w�趯�����콣��ɭɭ��һ�С�������������$n��$l",
		"dodge":		-60,
		"force":		180,
		"damage_type":	"����"
	]),
	([	
		"action":		"$N����$w��â������һ�С�ǧ����ת����˲������$n��$l��������",
		"dodge":		-40,
		"damage":		190,
		"damage_type":	"����"
	]),
	([	
		"action":		"$N����$wһȦ����������ɳ����ͻȻ����һ���������������⣬һ�С�������������$n$l��ȥ",
		"dodge":		-40,
		"damage":		140,
		"damage_type":	"����"
	]),
	([	
		"action":		"$N$w�������ó����콣Ӱ�����Ŵشأ�һ�С��������졹��ס$n��$l",
		"dodge":		60,
		"damage":		220,
		"damage_type":	"����"
	]),
	([	
		"action":		"$N����Ծ������$w�����佣����һ�С�������������ס$n��ȫ��",
		"dodge":		-60,
		"damage":		250,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w�ó����콣�⣬һ�С�����������������ɣ�������Ϣ��ת��$n�ı����ʹ�$n��$l",
                "damage":               190,
                "dodge" :               200,
                "parry" :               100,
		"damage_type":	"����"
	]),
	([	"action":		"$N��$w�߻��Σ�һ�С�������Ӱ������ס$n����·������ֱ��$n��$l",
		"damage":		130,
                "dodge" :               200,
                "parry" :               100,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ�С�������硹��$w�ҷ磬���϶��£����������$n��$l",
		"damage":		150,
                "dodge" :               200,
                "parry" :               100,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("foreknowledge", 1) < 100)
	{
		return notify_fail("���ռ��ѧ����ⲻ����û�а취ѧ����������\n");
	}
	
	if( (int)me->query("max_force") < 150 )
		return notify_fail("�������������û�а취������������\n");
	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry" || usage=="dodge";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 50
	||	(int)me->query("force") < 15 )
		return notify_fail("�����������������û�а취��ϰ����������\n");
	me->receive_damage("kee", 50);
	me->add("force", -15);
	write("�㰴����ѧ����һ������������\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/wuliang-sword/" + action;
}

int effective_level() { return 21;}

string *parry_msg = ({
        "$n�˽���ɣ���ʱ�ͽ�$N��$w���������⡣\n",
        "$n������ע���⣬$Nֻ������һ��$w�����ɳ���\n",
        "$n����$vԲת������������һ�С�����ɽ�ӡ���ǿ���Ľ����Ƶ�$N�������ˡ�\n",
});

string *unarmed_parry_msg = ({
        "$n�˽���ɣ���ʱ�ͽ�$N��$w���������⡣\n",
        "$n������ע���⣬$Nֻ������һ��$w�����ɳ���\n",
        "$n����$vԲת������������һ�С�����ɽ�ӡ���ǿ���Ľ����Ƶ�$N�������ˡ�\n",
        "$n�Ľ��ƺ�����������$Nֻ�����޴����֡�\n",
        "$n����������������������������ƫ��$N����ʽ�� \n",
        "$n������ɣ��Ƶ�$N�������ˡ�\n",        
});

string *dodge_msg = ({
                "$n����Ʈ����������Ӱ��������$N���԰��ա�\n",
                "$n�����ݿ�ȥ����$Nһʱ�޷�׷����\n",
                "$n������������$N������ǰʱȴ��һ��λ����ʹ$N���˸��ա�\n",
                "$n����һ�㣬ȫ���ڿգ���ʱ�㿪��$N־�ڱصõ���һ����\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
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

