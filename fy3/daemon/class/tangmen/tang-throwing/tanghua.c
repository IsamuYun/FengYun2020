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
		return notify_fail("[�ƻ�]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
extra = me->query_skill("tang-throwing",1) / 5;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
msg = RED "$N����һ����Ŷ��Ű���----һ�������ŷ�ɥ�����ƻ���$n���˳�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	target->apply_condition("unknown",random(10)+10);

return 1;
}
