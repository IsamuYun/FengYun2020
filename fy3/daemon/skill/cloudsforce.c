// iceforce.c2

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("�ƺ��ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("tieflag") + "/cloudsforce/" + func;
}

int effective_level() { return 11;}

int learn_bonus()
{
	return -10;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 15;
}

string belong()
{
	return "tieflag";
}