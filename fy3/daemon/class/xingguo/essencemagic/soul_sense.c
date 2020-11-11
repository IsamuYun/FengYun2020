// void_sense.c

#include <ansi.h>

inherit SSERVER;
int conjure(object me, object target)
{
	int lvl,i;
	object env, *inv;
	lvl = (int) me->query_skill("magic");
	lvl += (int) me->query("spi");
        if ( lvl <= 100)
                return notify_fail("�㷨�������ߣ�\n");
	if( me->query("atman") < 30 )
		return notify_fail("�������������\n");
        if( me->query("gin") <= 15 )
                return notify_fail("��ľ�������\n");
	me->add("atman", -30);
	me->receive_damage("gin", 15);
	message_vision(HIW "$N΢һ���񣬱����۾�ʹ����ʶ��ͨ�е���ʶ������\n" NOR, me);
	        me->add_temp("apply/astral_vision", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), lvl);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;

}
void remove_effect(object me)
{
        me->add_temp("apply/astral_vision", -1);
        tell_object(me, "�����ʶʧЧ�ˡ�\n");
}

