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

	if( !target
	|| !target->is_ghost()
	||	target==me
	||  userp(target) )
		return notify_fail("��ֻ�ܶԹ���������ͷ��\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("�����Ѫ������\n");
	if(!corp = present("corpse",environment(me)))
		return notify_fail("�����Χû��ʬ�壡\n");
	me->receive_wound("kee", 100);
	msg = HIC "$N��ն���$n��㼸�£�$n������վ��������\n\n" NOR;
	message_vision(msg,me,corp);
	destruct(corp);
	target->be_ghost(0);
	target->set("title",HIB"��ʬ����"NOR);
	me->start_busy(2);
	return 1;
}

