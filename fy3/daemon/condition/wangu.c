// wangudu.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("kee", 70);
        me->receive_wound("gin", 70);
        me->receive_wound("sen", 70);
        me->apply_condition("wangu", duration - 1);
        if( duration < 1 )
        tell_object(me, HIW "���е�" BLINK HIG "��" HIR "ɫ" MAG "��" HIW "��"HIC"��" NOR HIW "���ڷ������ˣ�\n" NOR );
        else
        switch( random(5) ) {
        case 0:
        tell_object(me, HIC "���е�" BLINK HIG "����" NOR HIC "�������ˣ�\n" NOR );
        break;
        case 1:
        tell_object(me, HIC "���е�" BLINK HIR "��Ы" NOR HIC "�������ˣ�\n" NOR );
        break;

        case 2:
        tell_object(me, HIC "���е�" BLINK MAG "����" NOR HIC "�������ˣ�\n" NOR );
        break;
        case 3:
        tell_object(me, HIC "���е�" BLINK HIW "���" NOR HIC "�������ˣ�\n" NOR );
        break;
        case 4:
        tell_object(me, HIC "���е�" BLINK WHT "ī��" NOR HIC "�������ˣ�\n" NOR );
        break;
        }
        if( duration < 1 ) 
                return 0;
        return 1;
}