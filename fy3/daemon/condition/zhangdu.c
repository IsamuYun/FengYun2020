// yihua_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 150);
        me->receive_wound("gin", 150);
        me->receive_wound("sen", 150);
        me->apply_condition("zhangdu", duration - 1);
        if( duration < 1 )
        tell_object(me, HIW "���е�" HIB "�����涾" HIW "���ڷ������ˣ�\n" NOR );
	else
        tell_object(me, HIW "���е�" HIB "�����涾" HIW  "�����ˣ�ʹ�������ȫ����һ����鴤....\n" NOR );
	if( duration < 1 ) 
		return 0;
	return 1;
}
