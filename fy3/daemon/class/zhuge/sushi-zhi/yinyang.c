// 阴差阳错  written by tiandi

#include <ansi.h>
#include <combat.h>
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
		return notify_fail("［阴差阳错］只能对战斗中的对手使用。\n");
	extra = me->query_skill("sushi-zhi",1);
	if(extra <= 80 ) return notify_fail("你的［俗世指］不够熟练！\n");
	if( me->query("TASK") < 1600  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("以你目前的状况，还没有资格用这一招。\n");
	if(extra> 220) extra=220;
	extra=extra*3;
	if(me->query("force")<300) return notify_fail("你的内力不够！\n");
	if( me->query("TASK") < 1500  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("以你目前的状况，还没有资格用这一招。\n");
	weapon = me->query_temp("weapon");
	me->add("force",-100);
	if(!me->query_temp("five")||me->query_temp("five")<1)
		{
		msg = HIR "$N口中大喝了一声，身形向后移动中，十指微曲，只听见“嗤嗤嗤嗤嗤嗤嗤嗤嗤嗤”，十道指风射向$n,「阴差阳错」已使了出去！\n"NOR;
        	me->add_temp("apply/damage",extra*2);
		me->add_temp("apply/attack",extra);
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add_temp("apply/damage",-extra*2);
        	me->add_temp("apply/attack",-extra);
		me->start_busy(2);
		}
	else if(random(10)<5)
		{
		msg = HIR "$N双手一错，食指向外横推而出，这一招「气吞山河」带着一股阳刚之气风一左一右戳向$n！\n"NOR;
			if(target->query("gender")=="女性")
			{
			msg += "$n娇嫩的身体似乎经不起$N这一击，$n打算盲目地躲开$N的这一指。";	
			me->add_temp("apply/damage",extra*5);
			me->add_temp("apply/attack",extra*5);
        		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
			me->add_temp("apply/damage",-extra*5);
        		me->add_temp("apply/attack",-extra*5);
			me->start_busy(3);
			me->add_temp("five",-1);
			}
			else 
			{
			msg += "$n抖擞精神，运起十层的轻功欲躲开$N的这一指。";	
			me->add_temp("apply/damage",extra*2);
			me->add_temp("apply/attack",extra);
        		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
			me->add_temp("apply/damage",-extra*2);
        		me->add_temp("apply/attack",-extra);
			me->start_busy(2);
			}
		}
		else
		{
		msg = HIR "$N娇喝一声，尾指弯曲成型，犹如一条银蛇，一招「婀娜风飞」带着一股纯阴之气风一前一后戳向$n！\n"NOR;
			if(target->query("gender")=="男性")
			{
			msg += "$n被$N以柔克刚，打出的所有招式都如石沉大海，只得回身撤招防守。";	
			me->add_temp("apply/damage",extra*5);
			me->add_temp("apply/attack",extra*5);
        		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
			me->add_temp("apply/damage",-extra*5);
        		me->add_temp("apply/attack",-extra*5);
			me->start_busy(3);
			me->add_temp("five",-1);
			}
			else 
			{
			msg += "$n借着灵巧的身法穿梭在$N的十指一间，同时寻觅着每一丝反击的机会。";	
			me->add_temp("apply/damage",extra*2);
			me->add_temp("apply/attack",extra);
        		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
			me->add_temp("apply/damage",-extra*2);
        		me->add_temp("apply/attack",-extra);
			me->start_busy(2);
			}
		}
	return 1;
}
