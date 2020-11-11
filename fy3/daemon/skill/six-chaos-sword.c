// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"Ⱥħ����",
		"action":		"$Nʹһ�С�Ⱥħ���衹������$w�����������$n��$l��������",
		"dodge":		50,
		"damage":		170,
		"damage_type":	"����"
	]),
	([	"name":			"�������",
		"action":		"$N����һת��һ�С��������$wն��$n��$l",
		"dodge":		-50,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"name":			"�ٹ�ҹ��",
		"action":		"$N�趯$w��һ�С��ٹ�ҹ�С�Ю�������������$n��$l",
		"dodge":		-40,
		"damage_type":	"����"
	]),
	([	"name":			"������·",
		"action":		"$N����$wһ����ʹ����������·����$n��$l�̳�һ��",
		"dodge":		-40,
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"name":			"��Ӱ����",
		"action":		"$N����$w���Ⱪ����һ�С���Ӱ��������$n$l��ȥ",
		"dodge":		-60,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"name":			"��ع�",
		"action":		"$N����$wֱָ$n$l��һ�С���ع����������˽�����ȥ",
		"dodge":		-20,
		"damage":		50,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������������û�а취������׷�꽣��\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
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
	||	(int)me->query("force") < 5 )
		return notify_fail("�����������������û�а취��ϰ����׷�꽣��\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("�㰴����ѧ����һ������׷�꽣����\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if( (int)me->query_skill("six-chaos-sword", 1)	% 10 == 0 ) {
		tell_object(me,
			RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
		me->add("bellicosity", 1000);
	} else
		me->add("bellicosity", 100);
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$n���˷������������죬һ�С������ޱߡ������е�$v�ݺݿĿ���$N��$w��\n",
	"$n�ؽ����أ�һ�С����Ʈ�㡹����ס��$N��$w��\n",
	"$nһ�С�Ⱥħ���衹�����е�$v����ǧ�ٰѣ���ס��ȫ��\n",
	"$n���е�$v�������£�������$N��$w�������Ρ�\n",
});

string *unarmed_parry_msg = ({
        "$nʹ��һ�С�����ħ�ϡ�������ǰ������һ��ͭǽ���ڣ���ס��$N�Ĺ��ơ�\n",
	"$nһ�����е�$v��ʹ��һ�С�����ħ�ݡ������е�$v��ס��ȫ��\n",
	"$n��$v������һ�̣�$v�����������պ�ֱ��$N��˫�ۡ�\n",
	"$n�ٽ�������һ�������ӽ���͸�����ƿ���$N��\n",
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
	return 0;
}
int black_white_ness()
{
	return -10;
}

