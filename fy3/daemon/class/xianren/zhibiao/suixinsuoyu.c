// tie@fengyun
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［随心所欲］只能对战斗中的对手使用。\n");
	extra = me->query_skill("zhibiao",1) ;
	if(extra <= 100 ) return notify_fail("你的［指镖］不够熟练！\n");
	me->add_temp("apply/attack",extra/10);
       weapon = me->query_temp("weapon");
       message_vision(YEL"$N左手一扬，发出专破内家真气的指镖。右手一招[所心所欲]发挥的淋漓尽至。\n"NOR,me,target);      
       msg = HIR "只见$n闪躲中已中了一击，口中鲜血不断喷出，似乎受了内伤。\n" NOR;
            	message_vision(msg, me, target);
      me->add_temp("apply/attack",-extra/10);
       target->receive_wound("kee", 100,me);
	me->start_busy(3);
	return 1;
}
