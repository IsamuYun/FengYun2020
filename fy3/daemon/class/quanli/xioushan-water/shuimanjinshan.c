// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("xioushan-water",1)* 2;
	if ( extra < 100) return notify_fail("���[��ɽ��ˮ��]���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[ˮ����ɽ]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add_temp("apply/attack", extra/5);me->add_temp("apply/damage", extra/5);
	
weapon = me->query_temp("weapon");
	msg = HIY  "$N����ͻȻ�������ˮ����ֱ��$n����һ����" NOR;
	COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR,msg);
        msg = HIY  "�ڶ�����" NOR;
        COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR,msg);
        msg = HIY  "��������" NOR;
        COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR,msg);
me->add_temp("apply/attack", -extra/5);me->add_temp("apply/damage", -extra/5);


	me->start_busy(5);
	return 1;
}
