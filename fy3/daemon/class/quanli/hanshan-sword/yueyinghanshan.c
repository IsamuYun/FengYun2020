// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("hanshan-sword",1);
	if ( extra < 40) return notify_fail("���[��ɽʮ��ʽ]���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ӳ��ɽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add_temp("apply/attack", extra);	me->add_temp("apply/damage", extra);

weapon = me->query_temp("weapon");
	msg = HIR  "$Nʹ����ɽʮ��ʽ�е����һʽ----����ӳ��ɽ�ݣ����е�"+ weapon->name()+ RED "ֱ��$n��˫ü��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "ֻ��$N�����ֶ��һ��"+ weapon->name()+ RED"�����ػ���$n����磡" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);
me->add_temp("apply/damage", -extra);

	me->start_busy(4);
	return 1;
}
