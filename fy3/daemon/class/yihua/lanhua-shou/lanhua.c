// tie@fengyun
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
        extra = me->query_skill("unarmed");
        if ( extra < 300) return notify_fail("��������ֻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
             return notify_fail("���������ţ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
     me->add("force_factor",extra/3);
        orforce = (int) me->query("force");
        me->add("force",extra/3*100);
        me->add_temp("apply/attack",extra/2);me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
        msg = HIR  "$N��ָ�ֿ���΢΢һ�����ٲ�£����һ����һʽ���������ţݣ�\n" NOR;
        msg += HIR   "��������$nȫ��ҪѨ��һ�ɿ���Ҳ�ܸо������ε������\n" NOR;
	          message_vision(msg,me,target);
        msg =  HIC  "\n   ����Ƶ��� \n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "\n         �����Ʊ��¡�\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "\n                  ������������\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "\n                           ������ŪӰ��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "\n                                    �����Բ��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
  
me->start_busy(2);
        me->set("force_factor",0);
        me->set("force", orforce);
        me->add_temp("apply/attack",-extra/2);me->add_temp("apply/damage",-extra*2);

	return 1;
}
