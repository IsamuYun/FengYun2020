#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("天女散花只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
         extra = me->query_skill("lanhua-sword",1) / 10;
	me->add_temp("apply/attack", extra);	
        me->add_temp("apply/damage", extra);
	msg = HIC  "$N脚踏［兰花步法］，同时使出［兰花剑法］中的精髓－［" + HIW"天女散花"WHT + "］，手中的"+ weapon->name() +"划出" + HIC"兰" + HIY"花" + HIG"般的圆圈击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
   COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
   COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//	message_vision(msg, me, target);
	me->add_temp("apply/attack", -extra);
         me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
