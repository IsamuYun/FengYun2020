// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 50);
        me->receive_wound("gin", 100);
        me->receive_wound("sen", 50);
	me->apply_condition("wanzhuo", duration - 1);
        if( duration < 1 )
	tell_object(me, HIW "你中的" HIR "万灼之毒" HIW "终于发作光了！\n" NOR );
	else
	tell_object(me, HIW "你中的" HIR "万灼之毒" HIW "发作了！\n" NOR );
	if( duration < 1 ) 
		return 0;
	return 1;
}
