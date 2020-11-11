// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;
	object corp;
	if( !target ) target = me;

        if((int)me->query_skill("xisui",1) < 120 )
                return notify_fail("���ϴ�辭�����ߣ�\n");

	if( !target || target != me)
		return notify_fail("��ֻ�ܶ��Լ����׽��\n");
        if( (int)target->query_temp("xisui") ) return
	notify_fail("�Ѿ���ʩչ�׽���ˡ�\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("�����Ѫ������\n");
	me->receive_wound("kee", 100);
	msg = HIC "$N������������ξ�Ȼ�ߴ���һ�أ���\n\n" NOR;
	message_vision(msg,me);
	target->add_temp("apply/strength", (int)target->query_str()/10);
	target->set_temp("xisui",1);
	target->start_busy(1);
	me->start_busy(2);
	        target->start_call_out( (: call_other, __FILE__, "remove_effect", target,
(int)target->query_str()/10 :), (int)me->query_skill("xisui")/7);

	return 1;
}
void remove_effect(object me, int amount)
{
        me->delete_temp("xisui");
        tell_object(me, "���ù���ϣ�ȫ��ָ�������\n");
	me->add_temp("apply/strength",-amount);
}

