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
		return notify_fail("［抽身法］只能在战斗中使用。\n");
	if( target != me)
		return notify_fail("［抽身法］只能对自己使用。\n");

	msg = YEL "$N虚晃一招，纵身向外跳开，企图避开敌人的攻势，\n" NOR;
	lvl = (int)me->query_skill("move");
	me->add_temp("apply/move",lvl);
        message_vision(msg, me);
	GO_CMD->do_flee(me);
	me->add_temp("apply/move",-lvl);
	me->start_busy(1);
	return 1;
}
