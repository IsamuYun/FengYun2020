// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) 
        	return notify_fail("��ֻ�ܽ������ս���������Լ������ϡ�\n");

        skill = me->query_skill("incarnation");

        if( (int)me->query("force") < skill )     return 
notify_fail("�������������\n");
        if( (int)target->query_temp("spi_powerup") ) return 
notify_fail("���Ѿ����˹����ˡ�\n");

        me->add("force", -skill);

        message_vision(
                HIW 
                "$N΢һ�����������ս����������ͻȻ��ߣ�\n" NOR, me);

        target->add_temp("apply/str", skill/6);
//        target->add("bellocosity", skill);
        target->add_temp("apply/damage", skill/3);
        target->set_temp("spi_powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", target, 
skill/3 :), me->query_spi());

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/damage", - amount);
        me->add_temp("apply/str", - amount/2);
//        me->add_temp("apply/sword", - amount/2);
        me->delete_temp("spi_powerup");
        tell_object(me, HIY "������ս��ʧЧ�ˡ�\n" NOR);
}
