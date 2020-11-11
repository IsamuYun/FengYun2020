// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (me->query_temp("poison_del"))
	{
		me->delete_temp("poison_del");
		return 0;
	}
	me->receive_wound("kee", 150);
        me->receive_wound("gin", 150);
        me->receive_wound("sen", 150);
	me->apply_condition("bat", duration - 1);
        if( duration < 1 )
	tell_object(me, HIW "���е�" HIC "�߲�����" HIW "���ڷ������ˣ�\n" NOR );
	else
	tell_object(me, HIW "���е�" HIC "�߲�����" HIW  "�����ˣ�\n" NOR );
	if( duration < 1 ) 
		return 0;
	return 1;
}