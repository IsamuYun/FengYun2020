// xgchen@zzfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
        if((int)me->query("myskill")<8)
		return notify_fail("�����ڻ�û��ʹ�����еı��£���\n");
	extra = me->query_skill("unarmed");
        if ( extra < 550) return notify_fail("����Դ�ȭ�����������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("ȭ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add("force_factor",extra/3);
	orforce = (int) me->query("force");
        me->add("force",extra/3);
	me->add_temp("apply/attack",extra);me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
	msg = HIY  "\n$Nʹ�����Դ���ȭ�����У�����������ȭ����$n��ȫ������\n" NOR;
	message_vision(msg,me,target);
	msg = HIG  "��һȭ" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "�ڶ�ȭ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "����ȭ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIG  "����ȭ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIG "����ȭ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIG "����ȭ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIG "����ȭ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIG "���һȭ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);me->start_busy(5);
	me->set("force_factor",0);
	me->set("force", orforce);
        me->add_temp("apply/attack",-extra);me->add_temp("apply/damage",-extra*2);

	return 1;
}
