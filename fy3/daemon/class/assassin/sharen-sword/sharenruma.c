// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt;
	object weapon;
	extra = me->query_skill_eff_lvl("sharen-sword",1);
	if ( extra < 90) return notify_fail("���ɱ�˽��������������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ɱ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	msg = HIY  "$N���Դ󷢣����е�"+ weapon->name()+  "��籩������$n������" NOR;
	message_vision(msg,me,target);
	me->add_temp("apply/attack",extra/10);
	me->add_temp("apply/damage",extra/10);
	lmt = random(5)+3;
	for(i=1;i<=lmt;i++)
	{
	msg =  HIR "��"+chinese_number(i)+"����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
        me->add_temp("apply/attack",-extra/10);
        me->add_temp("apply/damage",-extra/10);
	me->start_busy(5);
	return 1;
}
