// she_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("kee", 30);
        me->receive_wound("gin", 30);
        me->receive_wound("sen", 30);
        me->apply_condition("she_poison", duration - 1);
        if( duration < 1 )
        tell_object(me, HIW "�����ڵ�" HIG "���߶�" HIW "���ڷ������ˣ�\n" NOR );
        else
        tell_object(me, HIW "�����ڵ�" HIY "���߶�" HIW  "�����ˣ�\n" NOR );
        if( duration < 1 ) 
                return 0;
        return 1;
}