// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) 
        	return notify_fail("��ֻ�ܽ�����Ԫ����������Լ������ϡ�\n");

        skill = me->query_skill("incarnation");

        if( (int)me->query("force") < skill )     return 
notify_fail("�������������\n");
        if( (int)target->query_temp("spi_protect") ) return 
notify_fail("���Ѿ����˹����ˡ�\n");


        me->add("force", -skill);

        message_vision(
                HIW 
                "$N΢һ����������Ԫ���壬������ͻȻ��ߣ�\n" NOR, me);

        target->add_temp("apply/armor", skill/3);
       target->add_temp("apply/iron-cloth", skill/3);
        target->set_temp("spi_protect", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", target, 
skill/3 :), me->query_spi());

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
        me->add_temp("apply/iron-cloth", - amount);
        me->delete_temp("spi_protect");
        tell_object(me, HIY "�����Ԫ����ʧЧ�ˡ�\n" NOR);
}
