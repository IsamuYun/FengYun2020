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
	extra = me->query_skill("sharen-sword",1);
	if ( extra < 80) return notify_fail("��ģ�ɱ�˽����ݻ��������죡\n");
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "jinhong-steps")
			return notify_fail("��������أ���Ҫ�۽�粽���ݵ���ͣ�\n");
	tmp = me->query_skill("jinhong-steps",1);
	if ( tmp < 80 )return notify_fail("��ģ۽�粽���ݻ��������죡\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������أ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add_temp("apply/attack",tmp);
	me->add_temp("apply/damage",extra);
	weapon = me->query_temp("weapon");
	msg = HIW  "\n\n$N˫Ŀ��죬ͻȻ�任���У�ʹ��ɱ�˽����еĽ��֣�������أ�,���е�$w����������������籩������$n���� ����\n\n\n���죡\n$N����$w������˵����ޣ���ͷ�������������¿���$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "$N�����Ľ�����һ����ã��Ѫ��������,$nֻ������֫����..." NOR;
	if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp"))
	{
	message_vision(msg+"\n",me,target);
	message_vision( HIR "$N����һ�н��ʵʵ�ؿ��У���Ѫ��һ�����µ��˿����������\n" NOR,target);
	target->receive_wound("kee",extra);
	me->receive_heal("kee",extra);
	}	
	else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N���Ʋ��ã��Ǳ������˿�ȥ...\n" NOR,target);
	}
        msg = HIW  "��أ�\n$N����$w����˿˿ɱ��,��Ȼ����������$n������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "$N�����Ľ�����һ����ã��Ѫ��������,$nֻ������֫����..." NOR;
	if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp"))
	{
	message_vision(msg+"\n",me,target);
	message_vision( HIR "$N����һ�н��ʵʵ�ؿ��У���Ѫ��һ�����µ��˿����������\n" NOR,target);
	target->receive_wound("kee",extra);
	me->receive_heal("kee",extra);
	}	
	else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N���Ʋ��ã����ɵ����˿�ȥ...\n" NOR,target);
	}
        msg = HIW  "���飡\n$N����$w��׼$nһ���ҿ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "$N�����Ľ�����һ����ã��Ѫ��������,$nֻ������֫����..." NOR;
	if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp"))
	{
	message_vision(msg+"\n",me,target);
	message_vision( HIR "$N����һ�н��ʵʵ�ؿ��У���Ѫ��һ�����µ��˿����������\n" NOR,target);
	target->receive_wound("kee",extra);
	me->receive_heal("kee",extra);
	}	
	else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N���Ʋ��ã�����Ծ�˿�ȥ...\n" NOR,target);
	}
      me->start_busy(2);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
	return 1;
}
