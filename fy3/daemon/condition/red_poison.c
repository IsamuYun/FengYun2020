// snake_poison.c
// yiru@hero
// һ��������Ķ���heihei

#include <ansi.h>

int update_condition(object me, int duration)
{
    me->receive_damage("gin", 20);
        me->receive_damage("kee", 20);
    me->receive_damage("sen", 20);
        me->apply_condition("red_poison", duration);

        tell_object(me, HIW "���е�" HIR "�඾" HIW "�����ˣ�\n" NOR );
    me->set_temp("die_type","�඾��������");

        return 1;
}
string query_type() { return "poison"; }
