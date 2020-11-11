// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"a",
		"action":		"$N���е�$w��һ��ָ������$n��$l��������",
		"dodge":		50,
		"parry" :		100,
		"force":		170,
		"damage" :		50,
		"damage_type":	"����"
	]),
	([	"name":			"b",
		"action":		"$N����һת�����е�$w����������$n��$l���˹�ȥ",
		"dodge":		50,
		"damage":		70,
		"damage_type":	"����"
	]),
	([	"name":			"c",
		"action":		"$N����һ����$wЮ�������������$n��$l",
		"dodge":		40,
		"damage" :		50,
		"force" :		120,
		"damage_type":	"����"
	]),
	([	"name":			"d",
		"action":		"$N����һ�������е�$w�������ϴ���$n��$l",
		"dodge":		40,
		"damage":		80,
		"damage_type":	"����"
	]),
	([	"name":			"e",
		"action":		"$N����$w���Ⱪ������ǧ����Ы��$n$lҧȥ",
		"dodge":		60,
		"damage":		120,
		"damage_type":	"����"
	]),
	([	"name":			"f",
		"action":		"$N���е�$w���޷����ݵ��ٶ�ֱ��$n��$l",
		"dodge":		20,
		"force" :		100,
		"damage":		50,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 200 )
		return notify_fail("�������������û�а취��ɱ�˽�����\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("�����������������û�а취��ϰɱ�˽�����\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("�㰴����ѧ����һ��ɱ�˽�����\n");
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
int effective_level() { return 15;}

int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return -30;
}
int black_white_ness()
{
	return -20;
}

string perform_action_file(string action)
{
        return CLASS_D("assassin") + "/sharen-sword/" + action;
}

