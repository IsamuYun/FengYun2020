// celestial.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }
int effective_level() { return 13;}

int valid_learn(object me)
{
        if( (int)me->query("bellicosity") < (int)me->query_skill("doomforce") 
* 50 )
                return 
notify_fail("���ɱ���������޷������������嶾�񹦡�\n");

        return 1;
}

int practice_skill(object me)
{
        return 

notify_fail("�嶾��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("wudujiao") + "/force/" + func;
}

 
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
        return 50;

}