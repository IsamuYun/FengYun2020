// she_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("kee", 30);
        me->receive_wound("gin", 30);
        me->receive_wound("sen", 30);
        me->apply_condition("she_poison", duration - 1);
        if( duration < 1 )
        tell_object(me, HIW "你体内的" HIG "青蛇毒" HIW "终于发作光了！\n" NOR );
        else
        tell_object(me, HIW "你体内的" HIY "青蛇毒" HIW  "发作了！\n" NOR );
        if( duration < 1 ) 
                return 0;
        return 1;
}