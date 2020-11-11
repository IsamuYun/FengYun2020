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
	tell_object(me, HIW "你中的" HIC "七彩蝙蝠毒" HIW "终于发作光了！\n" NOR );
	else
	tell_object(me, HIW "你中的" HIC "七彩蝙蝠毒" HIW  "发作了！\n" NOR );
	if( duration < 1 ) 
		return 0;
	return 1;
}
