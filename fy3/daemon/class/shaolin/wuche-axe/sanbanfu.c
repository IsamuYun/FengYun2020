// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("wuche-axe",1);
	if ( extra < 70) return notify_fail("����򳹲��縫�����������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����師��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack",extra);
	msg = HIY  "$Nʹ���򳹲��縫���еģ����師�ݣ�һ���������������е�"+ weapon->name()+ HIY "��ɽ����$n������һ����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "�ڶ�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra);
	me->start_busy(5);
	return 1;
}
