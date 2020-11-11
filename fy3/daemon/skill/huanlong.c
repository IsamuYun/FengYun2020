// essencemagic.c

inherit SKILL;


int valid_enable(string usage) { return usage=="magic"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("serpentforce",1) < 50
        ||      (int)me->query_skill("serpentforce",1) <= (int)me->query_skill("huanlong",1) )
                return notify_fail("��ķ��Թ���Ϊ����������޷�ѧϰ��������\n");
        return 1;
} 

string conjure_magic_file(string spell)
{
        return CLASS_D("dragon") + "/magic/" + spell;
}
int effective_level() { return 15;}

int learn_bonus()
{
        return -10;
}
int practice_bonus()
{
        return -5;
}
int black_white_ness()
{
        return 60;
}
int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ��\n");
}
