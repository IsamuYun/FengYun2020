// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("shenji-steps",1);
	if ( extra < 50) return notify_fail("��ģ���������ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	message_vision("$N���������磬��������$n�����$n��һ��һ��������$N������֮�У�\n",me,target);
	if(random((int)target->query("combat_exp")) < 2*(int)me->query("combat_exp"))
	{
	message_vision("���$N�����ô�ʧɫ����æ���ң�\n",target);
	target->start_busy(3);
	}
	else{
	message_vision("���$N�������ţ�\n",me);
	me->start_busy(2);
	}
	return 1;
}
