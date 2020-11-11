// three_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
    if( duration < 0 )
        return 0;
    me->receive_wound("gin", (int)me->query("max_gin")/9);
    me->receive_damage("kee", (int)me->query("max_kee")/9);
    me->receive_damage("sen", (int)me->query("max_sen")/9);

    me->apply_condition("blood_poison", duration - 1);
    if( duration < 1 )
        message_vision( HIW "$N�е�" HIR"Ѫ����"HIW "���ڷ������ˣ�\n" NOR , me);
    else
        message_vision( HIW "$N�е�" HIR"Ѫ����"HIW "�����ˣ�\n" NOR , me);
    if(me->query_condition("three_poison")>0){
        message_vision( HIY "$N�е�"HIC"��ʬ��"HIY"��"HIR"Ѫ����"HIW"һ�����ˣ�\n" NOR , me);
        if(!me->query_temp("is_unconcious")) me->unconcious();
    }
    me->set_temp("die_type","Ѫ���ķ�������");
    if( duration < 1 )
        return 0;
    return 1;
}

int check_condition(object me)
{
    if(me->query_condition("crane_red")>0){
        me->apply_condition("crane_red", -1);
        message_vision( HIW "$N�е�" HIR "�׶���" HIW "����ˣ�\n" NOR , me);
        return 1;
    }
    return 0;
}

string query_type() { return "seven-poison"; }
