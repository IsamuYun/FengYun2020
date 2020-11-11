// beast_poison

#include <ansi.h>

int update_condition(object me, int duration)
{
    me->receive_damage("kee", 1000);

    me->start_busy(10);

    me->apply_condition("beast_poison", duration - 1);

    tell_object(me, HIW "你中的" NOR WHT "缠魂丝" HIW "发作了！动弹不得。\n" NOR );

    me->set_temp("die_type","被缠魂致死");

    if( duration < 1 ) return 0;
    return 1;
}

string query_type() { return "poison"; }
