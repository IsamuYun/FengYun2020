// iron-cloth.c

inherit SKILL;
#include <ansi.h>
void skill_improved(object me)
{
        int s;

        s = me->query_skill("incarnation", 1);
        if( s%10==9 && (int)me->query("spi") < s/5) {
                tell_object(me, HIW "����������������������������ˡ�\n" NOR);
                me->add("spi", 2);
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

int valid_enable(string usage) { return usage=="literate"; }
