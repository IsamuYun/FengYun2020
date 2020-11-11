// yiru@hero
// five-summon.c
// �����ٻ���

#include <ansi.h>
inherit SKILL;

int valid_enable(string usage) 
{ 
        return  usage=="incarnation";
}

void skill_improved(object me)
{
    int sk = me->query_skill("five-summon", 1);
        if( sk == 50)
                tell_object(me, HIC "���������������ٻ������������˷�ϵ�ٻ�����\n" NOR );
        if( sk == 100)
                tell_object(me, HIY "���������������ٻ���������������ϵ�ٻ�����\n" NOR );
        if( sk == 150)
                tell_object(me, HIB "���������������ٻ�������������ˮϵ�ٻ�����\n" NOR );
        if( sk == 200)
                tell_object(me, HIW "���������������ٻ���������������ϵ�ٻ�����\n" NOR );

        if( sk == 250)
                tell_object(me, HIR "���������������ٻ������������˻�ϵ�ٻ�����\n" NOR );
        if( sk == 300)
                tell_object(me, HIM "��ϲ�㣡�����������˶�����������ٻ�������\n" NOR );
}

int valid_learn(object me)
{
    return 1;
}

int effective_level() { return 22; }

int learn_bonus()
{
        return -2000;
}
int practice_bonus()
{
        return -2000;
}
int black_white_ness()
{
        return 100;
}

string summon_action_file(string action)
{
        return CLASS_D("baimiao") + "/five-summon/" + action;
}
