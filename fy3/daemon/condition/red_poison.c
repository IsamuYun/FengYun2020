// snake_poison.c
// yiru@hero
// 一个发不完的毒，heihei

#include <ansi.h>

int update_condition(object me, int duration)
{
    me->receive_damage("gin", 20);
        me->receive_damage("kee", 20);
    me->receive_damage("sen", 20);
        me->apply_condition("red_poison", duration);

        tell_object(me, HIW "你中的" HIR "赤毒" HIW "发作了！\n" NOR );
    me->set_temp("die_type","赤毒发作而死");

        return 1;
}
string query_type() { return "poison"; }
