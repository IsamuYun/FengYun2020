inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me) { return 1; }
int practice_skill(object me)
{
        return 
notify_fail("Ѫ���ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("bloomdoor") + "/bloom-force/" + func;
}
 
int effective_level() { return 10;}

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
        return 20;
}
