// iceshock.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	me->receive_damage("gin", 30);
	me->receive_wound("kee", 30);
	me->receive_damage("sen", 30);
	me->apply_condition("qicaibat", duration - 1);

	tell_object(me, HIB "你中的七彩蝙蝠毒发作了！\n" NOR );
	if( duration < 1 ) return 0;

	return CND_CONTINUE;
}
