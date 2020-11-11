#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target, int amount)
{
        if( target != me ) return 
notify_fail("��ֻ������Ӱ�ķ������Լ��Ķ�������\n");

        if( (int)me->query("force") < 100 )     return 
notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) return 
notify_fail("���Ѿ����˹����ˡ�\n");

        amount = me->query_skill("force");
        me->add("force", -100);
        me->receive_damage("kee", 0);

        message_vision(
                HIR 
"$N������Ӱ�ķ����������˺�һ�ľ��磬������շ���\n" NOR, me);
        
        me->add_temp("apply/dodge", amount/2);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
amount/3 :), amount);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        amount = me->query_skill("force");
        me->add_temp("apply/dodge", - amount/2);
        me->delete_temp("powerup");
        tell_object(me, "�����Ӱ�ķ����о�ת�����ص��\n");
}
