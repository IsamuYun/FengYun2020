// fonxanforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if(me->query("level")< 40)
		return notify_fail("��ĵȼ�������ʮ����\n");
	return 1;
}

int practice_skill(object me)
{
        return 
notify_fail("���ɾ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("baiyun") + "/feixianforce/" + func;
}
 
int effective_level() { return 20;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 100;
}
string belong()
{
	return "baiyun";
}