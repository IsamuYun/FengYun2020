// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("vivien-steps",1);
	if ( extra < 90) return notify_fail("��ģ����鲽���ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ȴǧ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	message_vision( HIY "$N�Ĳ����ɣ�" + HIW "���µ�һ�Ṧ--��ȴǧ��" + HIY "ʹ�˳�ȥ��\n" NOR ,me,target);
	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
	message_vision("���$N����һ�������ŵ�æ�ҳ�����֪���㣡\n",target);
	target->start_busy(5);
	}
	else{
	msg = "��ϧ$N������$n�����е�һ������������ѸȻ������";
	COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
	}
	return 1;
}
