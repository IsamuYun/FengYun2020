
inherit SKILL;

string *dodge_msg = ({
	"$nһ�С�����ʤ���项�������ɵر��˿�ȥ��\n",
	"ֻ��$n��Ӱһ�Σ�һʽ��һ����ˮ�����ѱ����߳�֮�⡣\n",
	"$nʹ��������һ���졹���������ɵ�������\n",
	"$n����һ�㣬һ�С�������̬���ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ�С����𡹣���������Ʈ�˿�ȥ��\n",
	"$n��Ӱ΢�����Ѿ���һ�С����项����������\n",
	"����$nһ�С����项ʹ���������Ƶ�$N���ᣡ\n",
        "����$n����Ʈ��������һ�ݣ�һ�С����项���ܿ���һ����\n",
        "$n��������һ�Σ�һ�С���Ե���ˡ���һ��ת����������֮�⡣\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������������û�а취�����鲽����\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("��������������������������鲽����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 15;}

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
        return CLASS_D("tiandi") + "/vivien-steps/" + action;
}

