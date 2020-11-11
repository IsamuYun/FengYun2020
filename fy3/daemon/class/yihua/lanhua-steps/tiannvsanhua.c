#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("天女散花对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("天女散花只能和兰花剑法配和！\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("天女散花只能和兰花剑法配和！\n");
	if ( (string) me->query_skill_mapped("sword") != "lanhua-sword")
	return notify_fail("天女散花只能和兰花剑法配和！\n");
	extra = me->query_skill("lanhua-sword",1) / 10;
	extra += me->query_skill("lanhua-steps",1) /10;
	me->add_temp("apply/attack", extra);    
	me->add_temp("apply/damage", extra);
	msg = HIC  "$N脚踏［兰花步法］，同时使出［兰花剑法］中的精髓－［" + HIW"天女散花"WHT + "］，手中的"+ weapon->name() +"划出" + HIC"兰" + HIY"花" + HIG"般的圆圈击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//	msg =  HIW "剑光一闪，消失．．．．\n" NOR;
//	message_vision(msg, me, target);
	for(i=0;i<extra/5;i++)
	{
//	msg = HIC  "$N脚踏［兰花步法］，同时使出［兰花剑法］中的精髓－［" + HIW"天女散花"WHT + "］，手中的"+ weapon->name() +"划出" + HIC"兰" + HIY"花" + HIG"般的圆圈击向$n！" NOR;
//	message_vision(msg, me, target);
	msg = HIC "$N身形一隐一现,又飞一剑！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
