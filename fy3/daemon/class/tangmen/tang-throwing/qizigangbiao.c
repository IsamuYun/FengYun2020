#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt;
	object weapon;
       if( !target ) target = offensive_target(me);
       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[七子钢镖]只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("tang-throwing",1);
	if ( extra < 90) return notify_fail("你的唐门暗器还不够纯熟！\n");
	msg = GRN  "$N使出唐门暗器中的七子钢镖，击向$n" NOR;
	message_vision(msg,me,target);
        me->add_temp("apply/attack",extra*6);
        me->add_temp("apply/damage",extra*6);
	lmt = random(5)+3;
	for(i=1;i<=lmt;i++)
	{
	msg =  BLU "第"+chinese_number(i)+"镖" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
        me->add_temp("apply/attack",-extra*6);
        me->add_temp("apply/damage",-extra*6);
	me->start_busy(5);
	return 1;
}

