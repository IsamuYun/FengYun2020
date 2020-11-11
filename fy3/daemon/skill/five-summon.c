// yiru@hero
// five-summon.c
// 五行召唤术

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
                tell_object(me, HIC "由于你勤研五行召唤术，你掌握了风系召唤术！\n" NOR );
        if( sk == 100)
                tell_object(me, HIY "由于你勤研五行召唤术，你掌握了土系召唤术！\n" NOR );
        if( sk == 150)
                tell_object(me, HIB "由于你勤研五行召唤术，你掌握了水系召唤术！\n" NOR );
        if( sk == 200)
                tell_object(me, HIW "由于你勤研五行召唤术，你掌握了雷系召唤术！\n" NOR );

        if( sk == 250)
                tell_object(me, HIR "由于你勤研五行召唤术，你掌握了火系召唤术！\n" NOR );
        if( sk == 300)
                tell_object(me, HIM "恭喜你！你终于掌握了对五行神灵的召唤能力！\n" NOR );
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
