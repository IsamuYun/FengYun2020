// five-steps.c

inherit SKILL;

string *dodge_msg = ({
    "����$n����������ˮ������һ����һʽˮ�־��еġ��鵶��ˮ������������ıܿ���һ����\n",
        "$n������ת���Ų����У�һʽ���С�ľ�־�����ٿ�ش�ľ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�ʹ���������еġ����־�����$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ��ó������Ӱ���ӻ������Դܿ����ߣ����˿�ȥ��\n",
        "$n����΢�Σ�ʹ�����С����־��������ݵ���$N�����\n",
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
            return notify_fail("������ֻ��ͨ����ʦ��ѧϰ��������\n");
	return 1;
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 10;
}
string belong()
{
	return "wudang";
}
