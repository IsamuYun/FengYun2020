// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
	object weapon;
	extra = me->query_skill("shenji-blade",1);
	if ( extra < 50) return notify_fail("��ģ���������ݻ��������죡\n");
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "shenji-steps")
			return notify_fail("�ۼƳ���������Ҫ����������ݵ���ͣ�\n");
	tmp = me->query_skill("shenji-steps",1);
	if ( tmp < 50 )return notify_fail("��ģ���������ݻ��������죡\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ۼƳ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add_temp("apply/attack",tmp);
	me->add_temp("apply/damage",extra);
	weapon = me->query_temp("weapon");
	msg = HIR  "\n\n$N�ӳ���������еľ�����ص�һʽ�������ƣ�����������������\n\n\n��սƪ��\n$N����$wֱ��$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "ʤսƪ��\n$N����$wб��$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "��սƪ��\n$N����$wƽ��$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "��սƪ��\n$N����$w�ῳ$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "��սƪ��\n$N����$w�ݶ�$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "��սƪ��\n$N����$w����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "��սƪ��\n$N����$w����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��սƪ��\n$N����$w�ӽ����������$nɱȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(6);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
	return 1;
}
