// pyrobat-steps.c

inherit SKILL;

string *dodge_msg = ({
        "����$n����Ʈ��������һ�ݣ�һ�С�Ұ����ʳ������������ıܿ���һ����\n",
        "$n������ת��һʽ��Ұ��б�ݡ���ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�ʹ����Ұ���������$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ�һ�С�Ұ���ϴڡ������Դܿ����ߣ����˿�ȥ��\n",
        "$n����΢�Σ�ʹ����Ұ�����������о����յرܿ���$N��һ�С�\n",
        "$n��������һ�Σ�һ�С�Ұ����ҡ����һ��ת����������֮�⡣\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("�������̫���ˣ�������Ұ��������\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 9;}

int learn_bonus()
{
	return 50;
}
int practice_bonus()
{
	return 50;
}
int black_white_ness()
{
	return 50;
}

string perform_action_file(string action)
{
        return CLASS_D("beggar") + "/doggiesteps/" + action;
}

