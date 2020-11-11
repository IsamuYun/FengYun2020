// witchery.c
// ����

inherit SKILL;

int valid_enable(string usage) 
{ 
    return (usage=="herb") || (usage=="poison") ;
}

string perform_action_file(string action)
{
    return CLASS_D("baimiao") + "/witchery/" + action;
}

int valid_learn(object me) 
{
        if( ((int)me->query_skill("witchery",1)>=60) && (string)me->query("class") != "baimiao")
                return notify_fail("���޷�ѧ���������������\n");
        return 1;
}

int practice_skill(object me)
{       
        return 0;
}

int effective_level() { return 14;}

int learn_bonus()
{
        return 14;
}
int practice_bonus()
{
        return 7;
}
int black_white_ness()
{
        return -49;
}
