// yihua_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 150);
        me->receive_wound("gin", 150);
        me->receive_wound("sen", 150);
	me->apply_condition("huadu", duration - 1);
        if( duration < 1 )
	tell_object(me, HIW "你中的" HIY "迷花奇毒" HIW "终于发作光了！\n" NOR );
	else
	tell_object(me, HIW "你中的" HIY "迷花奇毒" HIW  "发作了！痛苦中你的全身不禁一阵阵抽搐....\n" NOR );
	if( duration < 1 ) 
		return 0;
	return 1;
}
