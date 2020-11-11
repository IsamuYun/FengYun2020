// five.c writted by tiandi

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
	  string msg;
		int damage, ap, dp;
		int extradam;
        if( !me->is_fighting() )
                return notify_fail("[金木水火土]只能在战斗中使用。\n");
		if( !target ) target = offensive_target(me);
		if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展这个奇术？\n");

        if( (int)me->query("force") - (int)me->query("max_force") < 300 )
                return notify_fail("你的真气不够。\n");
      
        msg=  me->name() + 
"百忙中突然灵机一动，脚踩八卦步，口中念念有词“"+HIY+"金----"+HIB+"木----"+HIC+"水----"+HIR+"火----"+HIM+"土----"+NOR+"！”\n\n";
      		message_vision(msg, me);
          
	 if( !me->query_temp("five")||me->query_temp("five")==0)
		{
		msg=HIY"     ※※※※※※※※※  [金]  ※※※※※※※※※\n\n"NOR;
		me->add_temp("five",1);
      		}
	else  if( me->query_temp("five")==1)
			{
			msg=HIB"     ※※※※※※※※※  [木]  ※※※※※※※※※\n\n"NOR;

			me->add_temp("five",1);
      		}
	else  if( me->query_temp("five")==2)
			{
			msg=HIC"     ※※※※※※※※※  [水]  ※※※※※※※※※\n\n"NOR;

			me->add_temp("five",1);
      		}
	else  if( me->query_temp("five")==3)
			{
			msg=HIR"     ※※※※※※※※※  [火]  ※※※※※※※※※\n\n"NOR;

			me->add_temp("five",1);
      		}
	else  if( me->query_temp("five")==4)
			{
			msg=HIM"     ※※※※※※※※※  [土]  ※※※※※※※※※\n\n"NOR;

			me->set_temp("five",0);
      		}
		ap = me->query_skill("force");
		extradam = ap/2;
		ap = ( ap * ap /100 * ap / 4 ) * (int)me->query("sen") ;
		dp = target->query("combat_exp");
		if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_mana") / 40 + random((int)me->query("eff_sen") / 20) + random(extradam);
		damage -= (int)target->query("max_mana") / 30 + random((int)me->query("eff_sen") / 15);
		if( damage/2 > 0 ) {
			msg +=  "结果「嗤」地一声，$n身上莫名其妙地流血了！\n"NOR;
			target->receive_damage("kee", damage);
			target->receive_wound("kee", damage/3);
			} else
			msg += "结果「嗤」地一声，光芒一闪而逝。。。\n"NOR;
	} else
		msg += "但是被$n躲开了。\n"NOR;
		message_vision(msg, me,target);
		if( damage/2 > 0 ) COMBAT_D->report_status(target);
		me->add("force",-300);
		me->start_busy(2);
        return 1;
}
 
