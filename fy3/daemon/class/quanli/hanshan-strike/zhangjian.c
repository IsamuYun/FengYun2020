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
		return notify_fail("���ƽ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("hanshan-strike",1) ;
	if( extra <=60) return notify_fail("���[��ɽ�Ʒ�]������������\n");
	me->add_temp("apply/attack", extra/5);	
	me->add_temp("apply/damage", extra/5);
	msg = HIR  "$N˫�ƻ��ཻ��ͻһ����˫�ֻ���Ϊ������$n��ȥ��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIR  "ֻ��$N����һ�⣬ײ��$n�����ţ�" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       msg = HIR  "$N��һ����˫�Ƽ���$n��ȥ��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIR  "$N���ֺ��أ����ֺ�һ���ƣ������Ѿõ�[�ƽ�]�ƿ���$n��ȥ��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
me->add_temp("apply/attack", -extra/5);
	me->add_temp("apply/damage", -extra/5);
	me->start_busy(4);
	return 1;
}
