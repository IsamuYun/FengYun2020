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
		return notify_fail("�۹�����ǽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if((int)me->query("kee")*100/(int)me->query("max_kee") > 20)
		return notify_fail("�㲻���򲻵��Ե�ʱ��ʹ�������У�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("doggiesteps",1) / 5;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N���һ���������类�Ƽ���Ұ����˫��һǰһ�󣬺�������$n�߳���" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
	me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
