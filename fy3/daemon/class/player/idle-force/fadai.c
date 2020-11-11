// tie@fengyun

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
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[发呆]只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
       if( (int)me->query("force") < 20 )    
       return  notify_fail("你的内力不够。\n");
	
	if ( (string) me->query_skill_mapped("force") != "idle-force")
	return notify_fail("发呆只能和发呆神功心法配和！\n");
      
	extra = me->query_skill("idle-force",1) / 10;
      
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIY  "$N呆头呆脑，竟然使用出发呆神功－－[发呆]，横着向$n撞去！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIY ". . ．．．．\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
	msg = HIC "$N攻出一招，虽然动作缓慢,依然威力无穷！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
       me->add("force", -20);
	me->start_busy(4);
	return 1;
}
