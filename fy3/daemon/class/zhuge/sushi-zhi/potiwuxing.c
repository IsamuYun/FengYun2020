// ��������
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg,msgg;
	int extra,orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("sushi-zhi",1);
	if ( extra < 150) return notify_fail("�������ָ���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��"HIR"��"HIW"��"HIB"��"HIY"��"NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
				orforce = (int) me->query("force");

	if (target->query_skill_mapped("iron-cloth"))
	{
	me->add_temp("apply/attack",extra*4);
	me->add_temp("apply/damage",extra*8);
	me->add("force_factor",1000);
			
	} else 
	{
	me->add_temp("apply/attack",extra/20);
	me->add_temp("apply/damage",extra/20);
	}
	msgg = "\n$n������Ӳ���Կ�$N�ģ�"HIR"��"HIW"��"HIB"��"HIY"��"NOR"�ݣ���������书��ˣ�$n��Ӳ�������޴�ʩչ��";
	weapon = me->query_temp("weapon");
	msg = HIY  "\n$N̤���鲽������΢б�������֮ʽ����ʵ���飬�������͡���������������\n";
	msg +="���ַ��Գ��Σ�����״�����࣡����������������ָ������$n��\n";
	msg +=HIG"$n����ʧ���е���"NOR;
	          message_vision(msg,me,target);
       msg =  HIC  "\n     	 -------  �� �� �� �� �� �� ��  -------\n" NOR;
	if (target->query_skill_mapped("iron-cloth"))
	msg += msgg;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIR  "\n ������Ⱦ������\n" NOR;
       if (target->query_skill_mapped("iron-cloth"))
	msg += msgg;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIW  "\n            ����ɽ����ʼ��Ψ��\n" NOR;
       if (target->query_skill_mapped("iron-cloth"))
	msg += msgg;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "\n                       ���񴺷��������\n" NOR;
       if (target->query_skill_mapped("iron-cloth"))
	msg += msgg;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC "\n                                    ����ȻһЦĺ�ƻ��\n" NOR;
       if (target->query_skill_mapped("iron-cloth"))
	msg += msgg;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
  	me->start_busy(3);	
	if (target->query_skill_mapped("iron-cloth"))
	{
	me->add_temp("apply/attack",-extra*4);
	me->add_temp("apply/damage",-extra*8);
	} else 
	{
	me->add_temp("apply/attack",-extra/20);
	me->add_temp("apply/damage",-extra/20);
	}
	me->set("force_factor",0);
	me->set("force", orforce);
return 1;
}
