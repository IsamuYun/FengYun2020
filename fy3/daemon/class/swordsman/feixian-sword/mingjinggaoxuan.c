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
		return notify_fail("［明镜高悬］只能对战斗中的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正被你的剑招弄的手忙脚乱，放心攻吧！\n");

	msg = HIW "$N使出飞仙剑法中的封招绝技「明镜高悬」，试图封住$n的攻势，";
	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "结果$p被$P攻了个措手不及！\n" NOR;
		target->start_busy( (int)me->query_skill("feixian-sword") / 20 + 2);
	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
