// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۽����޻ڣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("unarmed") / 10 + 1;
	msg = HIR "$N���۽���ʮ���ƣݵ�ʮ��ʽ�ܻ��ͨ���ó�ʮ�˸���Ӱһ������$n��ʮ�˴�Ҫ����" NOR;
	if(random(yourexp) < myexp)
	{
	if( random(2))
	{
		message_vision(msg + "\n", me, target);
		msg = "���$n��$N���˸���æ���ң�\n";
		message_vision(msg, me, target);
		target->start_busy(3);
	}
	else
	{
			me->add_temp("apply/attack", lvl);
			me->add_temp("apply/damage",lvl);
		        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
			me->start_busy(2);
			me->add_temp("apply/attack", -lvl);
                        me->add_temp("apply/damage",-lvl);
	}
	}
	else
	{
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->start_busy(2);
	}

	return 1;
}
