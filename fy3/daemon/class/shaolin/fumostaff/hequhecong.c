// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,myexp, hisexp;
	object weapon;
	extra = me->query_skill("fumostaff",1);
	if ( extra < 200) return notify_fail("���Τ�ӷ�ħ�ȷ����������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ۺ�ȥ�δӣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	myexp = (int) me->query("combat_exp");
	hisexp= (int)target->query("combat_exp");
	message_vision("$Nչ��Τ�ӷ�ħ�ȷ�����Ȼ�ó�����ã���֣�\n",me);
	if(random(hisexp) < myexp * 2)
	{
	target->start_busy(5);
	message_vision("$N���ȷ����󣬶�������������\n",target);
	}
	else
	{
	me->start_busy(2);
	message_vision("$N����ľٶ������޶ã�\n",target);	
	}
	return 1;
}
