//mouse@skill
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me) { return 1; }
int practice_skill(object me)
{
        return 
notify_fail("��ڤ��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("dali") + "/force/" + func;
}
 
int effective_level() { return 25;}

int learn_bonus()
{
        return 100;

}
int practice_bonus()
{
        return 100;
}
int black_white_ness()
{
        return 20;
}
