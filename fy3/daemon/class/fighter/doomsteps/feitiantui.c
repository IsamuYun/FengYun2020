// tie@fengyun

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
		return notify_fail("�۷����ȣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("doomsteps",1) / 10;
	me->add_temp("apply/attack", extra);	
	msg = HIR  "$N��һ������Ѹ���ޱȵ���$n�߳�����һ�ȣ�" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
	me->add_temp("apply/attack", -extra);
	me->start_busy(2);
	return 1;
}
