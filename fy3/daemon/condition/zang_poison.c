// zang_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_damage("gin", 100);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 100);
        me->apply_condition("zang_poison", duration - 1);
        tell_object(me, HIY "你中的" NOR YEL "瘴毒" HIY "发作了！\n" NOR );
    me->set_temp("die_type","瘴毒发作而死");
        if( duration < 1 ) return 0;
        return 1;
}

string query_type() { return "poison"; }
