// zang_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_damage("gin", 100);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 100);
        me->apply_condition("zang_poison", duration - 1);
        tell_object(me, HIY "���е�" NOR YEL "�ζ�" HIY "�����ˣ�\n" NOR );
    me->set_temp("die_type","�ζ���������");
        if( duration < 1 ) return 0;
        return 1;
}

string query_type() { return "poison"; }
