// three_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
    if( duration < 0 )
        return 0;
    me->receive_wound("gin", (int)me->query("max_gin")/7);
    me->receive_damage("kee", (int)me->query("max_kee")/7);
    me->receive_damage("sen", (int)me->query("max_sen")/7);

    me->apply_condition("bowel_grass", duration - 1);
    if( duration < 1 )
        message_vision( HIW "$N�е�" HIG "�ϳ���" HIW "���ڷ������ˣ�\n" NOR , me);
    else
        message_vision( HIW "$N�е�" HIG "�ϳ���" HIW "�����ˣ�\n" NOR , me);
    if(me->query_condition("gold_worm")>0){
        message_vision( HIY "$N�е�"HIG "�ϳ���" HIW"��" HIY"��Ϲ�"HIW "һ�����ˣ�\n" NOR , me);
        if(!me->query_temp("is_unconcious")) me->unconcious();
    }
    me->set_temp("die_type","�ϳ��ݷ�������");
    if( duration < 1 )
        return 0;
    return 1;
}

int check_condition(object me)
{
    if(me->query_condition("blood_poison")>0){
        me->apply_condition("blood_poison", -1);
        message_vision( HIW "$N�е�" HIR "Ѫ����" HIW "����ˣ�\n" NOR , me);
        return 1;
    }
    return 0;
}
string query_type() { return "seven-poison"; }
