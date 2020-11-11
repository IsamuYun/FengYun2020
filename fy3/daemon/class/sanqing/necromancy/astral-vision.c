// astral_vision.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int skill;

	if( me->query_temp("apply/astral_vision") )
		return notify_fail("���Ѿ�ʩչ�������۵ķ����ˡ�\n");

	if( (int)me->query("mana") < 30 )
		return notify_fail("��ķ���������\n");

	skill = me->query_skill("spells");

	me->add("mana", - 30);
	me->receive_damage("sen", 5);

	message_vision(
		HIB "$N΢һ���񣬱����۾����˼������ʩչ�������ۡ�������\n" NOR, me);

	me->add_temp("apply/astral_vision", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me)
{
	me->add_temp("apply/astral_vision", -1);
	tell_object(me, "��������۷���ʧЧ�ˡ�\n");
}
