// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
	int s;

	s = me->query_skill("foreknowledge", 1);
        if( s%10==9 && (int)me->query("kar") < s/5) {
		tell_object(me, HIW "��춶�ռ��ѧ�ĸ���һ������⣬�����������ˡ�\n" NOR);
		me->add("kar", 2);
	}
}

int learn_bonus()
{
	return 10;
}

int practice_bonus()
{
	return 0;
}

int black_white_ness()
{
	return 0;
}

