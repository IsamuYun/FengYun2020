// wangudu.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("kee", 70);
        me->receive_wound("gin", 70);
        me->receive_wound("sen", 70);
        me->apply_condition("wangu", duration - 1);
        if( duration < 1 )
        tell_object(me, HIW "你中的" BLINK HIG "五" HIR "色" MAG "灵" HIW "虫"HIC"毒" NOR HIW "终于发作光了！\n" NOR );
        else
        switch( random(5) ) {
        case 0:
        tell_object(me, HIC "你中的" BLINK HIG "青蛇" NOR HIC "毒发作了！\n" NOR );
        break;
        case 1:
        tell_object(me, HIC "你中的" BLINK HIR "赤蝎" NOR HIC "毒发作了！\n" NOR );
        break;

        case 2:
        tell_object(me, HIC "你中的" BLINK MAG "褐蜈" NOR HIC "毒发作了！\n" NOR );
        break;
        case 3:
        tell_object(me, HIC "你中的" BLINK HIW "白蟾" NOR HIC "毒发作了！\n" NOR );
        break;
        case 4:
        tell_object(me, HIC "你中的" BLINK WHT "墨蛛" NOR HIC "毒发作了！\n" NOR );
        break;
        }
        if( duration < 1 ) 
                return 0;
        return 1;
}