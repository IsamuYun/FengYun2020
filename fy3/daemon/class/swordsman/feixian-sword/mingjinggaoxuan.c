// counterattack.c
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ������Ľ���Ū����æ���ң����Ĺ��ɣ�\n");

	msg = HIW "$Nʹ�����ɽ����еķ��о�������������������ͼ��ס$n�Ĺ��ƣ�";
	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "���$p��$P���˸����ֲ�����\n" NOR;
		target->start_busy( (int)me->query_skill("feixian-sword") / 20 + 2);
	} else {
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
