// toxin.c

#include <ansi.h>

inherit SKILL;
void skill_improved(object me)
{
        int s;

        s = me->query_skill("toxin", 1);
        if( s%10==9 && (int)me->query("cps") < s/5) {
                tell_object(me, HIW 
"由於你的毒术修炼有成，你的定力改善了。\n" NOR);
                me->add("cps", 2);
        }
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
        return 0;
}
