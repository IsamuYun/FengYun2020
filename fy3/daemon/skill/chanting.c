// scratching.c

inherit SKILL;
string type() { return "knowledge"; }
#include <ansi.h>
void skill_improved(object me)
{
        int s;

        s = me->query_skill("chanting", 1);
        if( s%10==9 && (int)me->query("cps") < s/5) {
                tell_object(me, HIW
"�������о������гɣ���Ķ��������ˡ�\n" NOR);
                me->add("cps", 2);
        }
}

int effective_level()
{ return 10;}

int learn_bonus()
{
        return -15;
}
int practice_bonus()
{
        return -5;
}
int black_white_ness()
{
        return 50;
}

