// xgchen@zzfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, myexp, hisexp;
	object weapon;
        if(me->query("family/family_name") != "������")
		return notify_fail("�㲻�����ֵ��Ӳ���ʹ�÷�����������\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("rulai-fofa",1) ;
	if ( extra < 70) return notify_fail("��������𷨻��������죡\n");
		

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۷���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = target->query_temp("weapon");
	myexp = (int)me->query("combat_exp");
	hisexp= (int)target->query("combat_exp");
	if(random(hisexp) < myexp * 2 && weapon)	
	{
	message_vision(
HIM "\n\n$N��Ŀ��������������............."HIY"\n\n\t�۷���������\n"HIM"\n$n���еı���"HIY+ 
weapon->name()+ HIM "���ֶ��ɣ�\n\n" NOR, me,target);
	if( weapon->unequip()) weapon->move(environment(target));
	}
	else
	{
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
	msg = HIY+ "\n\n$N��$n����������"HIY"----�����������ҷ�ȱ�----\n\n"HIC"һ��������������$n��$l��\n"+ NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);
	msg = HIY+ "\n\n$N��$n����������"HIY"----�����������ҷ���----\n\n"HIC"һ��������������$n��$l��\n"+ NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);
      me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
	me->start_busy(5);
	}
	return 1;
}
