// tie@fengyun
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int force,extra;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［破气式］只能对战斗中的对手使用。\n");
	extra = me->query_skill("dugu-sword",1) ;
	if(extra < 176 ) return notify_fail("你的［独孤九剑］不够熟练！\n");
       force = target->query("max_force");
       message_vision(HIB"$N暗运独孤九剑「破气式」，一股氤氲正气浩然而出, 当真是剑落鬼神惊！ \n"NOR,me,target);      
       msg = HIB "$n浑身剧震，诸般大穴似乎都被点中，内力尽失！\n" NOR;
            	message_vision(msg, me, target);
if(target->query("max_force")>200) {target->set("max_force",force/2 );}
	me->start_busy(3);
	return 1;
}
