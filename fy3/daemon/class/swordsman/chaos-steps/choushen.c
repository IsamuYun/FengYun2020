// counterattack.c

#include <ansi.h>
#include <command.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl;
	if( !target ) target = me;
	if(!me->is_fighting() )
		return notify_fail("�۳�����ֻ����ս����ʹ�á�\n");
	if( target != me)
		return notify_fail("�۳�����ֻ�ܶ��Լ�ʹ�á�\n");

	msg = YEL "$N���һ�У�����������������ͼ�ܿ����˵Ĺ��ƣ�\n" NOR;
	lvl = (int)me->query_skill("move");
	me->add_temp("apply/move",lvl);
        message_vision(msg, me);
	GO_CMD->do_flee(me);
	me->add_temp("apply/move",-lvl);
	me->start_busy(1);
	return 1;
}
