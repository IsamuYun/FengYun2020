// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 50);
        me->receive_wound("gin", 100);
        me->receive_wound("sen", 50);
	me->apply_condition("wanzhuo", duration - 1);
        if( duration < 1 )
	tell_object(me, HIW "���е�" HIR "����֮��" HIW "���ڷ������ˣ�\n" NOR );
	else
	tell_object(me, HIW "���е�" HIR "����֮��" HIW "�����ˣ�\n" NOR );
	if( duration < 1 ) 
		return 0;
	return 1;
}
