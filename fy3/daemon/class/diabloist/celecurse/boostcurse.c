#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;
	object corp;
	if( !target ) target = offensive_target(me);

        if((int)me->query_skill("cursism") < 120 )
                return notify_fail("��Ľ�ͷ�������ߣ�\n");

	if( !target || target != me)
		return notify_fail("��ֻ�ܶ��Լ��������ͷ��\n");
        if( (int)target->query_temp("boostcurse") ) return
	notify_fail("�Ѿ������˽�ͷ��\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("�����Ѫ������\n");
	me->receive_wound("kee", 100);
	msg = HIC "$N���쳤Х������ؼ��������Ϊһ�壮����\n\n" NOR;
	message_vision(msg,me);
	target->add_temp("apply/agility", (int)target->query_agi()/5);
	target->set_temp("boostcurse",1);
	target->start_busy(1);
	me->start_busy(2);
	        target->start_call_out( (: call_other, __FILE__, "remove_effect", target,
(int)target->query_agi()/5 :), (int)me->query_skill("cursism")/7);

	return 1;
}
void remove_effect(object me, int amount)
{
        me->delete_temp("boostcurse");
        tell_object(me, "�����ϵĵĽ�ͷʧЧ�ˣ�\n");
	me->add_temp("apply/agility",-amount);
}

