// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$nһ�С���ˮ�صޡ��������ɵر��˿�ȥ��\n",
	"ֻ��$n��Ӱһ�Σ�һʽ��������̡����ѱ����߳�֮�⡣\n",
	"$nʹ������ת��С����������ɵ�������\n",
	"$n����һ�㣬һ�С���Ӱ�������ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ�С��綯�񶯡�����������Ʈ�˿�ȥ��\n",
	"$n��Ӱ΢�����Ѿ���һ�С�������������������\n",
	"����$nһ�С���ҡ�ɵء�ʹ���������Ƶ�$N���ᣡ\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 20 )
		return notify_fail("�������������û�а취��佻�������\n");

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
		return notify_fail("�����������������������佻�������\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 20;}

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
	return 10;
}

string perform_action_file(string action)
{
        return CLASS_D("shenzhou") + "/huanhua-steps/" + action;
}

