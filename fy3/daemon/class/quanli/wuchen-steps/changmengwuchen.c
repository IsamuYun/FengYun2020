// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("wuchenforce",1);
	if ( extra < 50) return notify_fail("��ģ��޳��ķ��ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۳����޳���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ�æ��ʧ�룡\n");
	message_vision( HIY "$N��̤�˷���Ŀ�����ܣ���������֮����\n" NOR ,me,target);
	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
	message_vision("���$N���Եò�֪����\n",target);
	target->start_busy(2);
	}
	else{
	msg = "��ϧ$N������$n���޳�������$nѸȻ������";
	COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
	}
	return 1;
}
