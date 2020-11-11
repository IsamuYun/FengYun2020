// beast_poison

#include <ansi.h>

int update_condition(object me, int duration)
{
    me->receive_damage("kee", 1000);

    me->start_busy(10);

    me->apply_condition("beast_poison", duration - 1);

    tell_object(me, HIW "���е�" NOR WHT "����˿" HIW "�����ˣ��������á�\n" NOR );

    me->set_temp("die_type","����������");

    if( duration < 1 ) return 0;
    return 1;
}

string query_type() { return "poison"; }
