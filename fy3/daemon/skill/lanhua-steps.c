// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$nһ�С��ʵ����衹�������ɵر��˿�ȥ��\n",
	"ֻ��$n��Ӱһ�Σ�һʽ�����ѵ�ˮ�����ѱ����߳�֮�⡣\n",
	"$nʹ������ת��Ȩ�����������ɵ�������\n",
	"$n����һ�㣬һ�С����񾪷ɡ��ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ�С�΢�縧Ҷ������������Ʈ�˿�ȥ��\n",
	"$n��Ӱ΢�����Ѿ���һ�С�մ¶�軨������������\n",
	"����$nһ�С����·ת��ʹ���������Ƶ�$N���ᣡ\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취�����ϲ�����\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 0
	||      (int)me->query("force") < 0 )
		return notify_fail("��������������������������ϲ�����\n");
	me->receive_damage("kee", 0);
// me->add("force",1);
	return 1;
}
int effective_level() { return 22;}

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
	return 0;
}

string perform_action_file(string action)
{
	return CLASS_D("yihua") + "/lanhua-steps/" + action;
}

