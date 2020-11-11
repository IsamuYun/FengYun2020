// chansi.c
//written by kouga
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        int skill,lv;
	string msg;
	object weapon;
	lv = me->query("chansi");
	if (!lv)  me->set("chansi",1);
	lv = me->query("chansi");

	skill = me->query_skill("tie-steps",1);
	if(skill < 100) return notify_fail("你的铁血十二势太差了！\n"); 
	if( !target ) target = offensive_target(me);	
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［缠丝势］只能对战斗中的对手使用。\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
        if( (int)me->query("force") < 100*lv )     return
        notify_fail("你的内力不够。\n");
        if( (int)target->query_temp("chansi") ) return 
	notify_fail("你已经在施展［缠丝势］了。\n");
       	if(random((int)target->query("level")) < random((int)me->query("level"))+lv)
	{
		me->add("force", -100*lv);
        	message_vision( HIR
		"$N轻身一跃，使出［缠丝势］，$n的身形受你的影响，变的生涩起来！\n" NOR, me,target);
        	target->add_temp("apply/dodge", -skill*2);
		target->add_temp("apply/parry",-skill*2);       
        	target->set_temp("chansi", 1);
        	seteuid(ROOT_UID);
        	target->start_call_out( (: call_other, __FILE__, "remove_effect", me,target, 
-skill*2 :), lv*10);
			seteuid(getuid());
        	me->start_busy(4);
	}
	else
	{
		msg = "可惜$N看出了$n的身法，向你迅然攻击！";
		COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
        	me->start_busy(2);
	}
        return 1;
}

void remove_effect(object me,object target, int amount)
{
        target->add_temp("apply/dodge", - amount);
	target->add_temp("apply/parry",- amount);
        target->delete_temp("chansi");
        message_vision("$N终于摆脱了［缠丝势］的影响。\n",target);
		if(me->query("chansi") < (target->query("level")/10) && !userp(target))
	{
	  me->add("chansi_exp",1);
	      tell_object(me, "你的【缠丝势】获得了一点技能熟练度。\n"NOR);
	  if(me->query("chansi_exp") > (me->query("chansi")*me->query("chansi")*100)&&(me->query("chansi")<10))
		{
		me->add("chansi",1);
		me->set("chansi_exp",0);
	      tell_object(me, HIW"你的【缠丝势】熟练上升了。\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n铁血之缠丝势："NOR"\n");
	write(@HELP

      此招可以减少施放目标的临时物理防御和物理闪避能力。
	
      铁血十二式等级每上升一级能提高目标减少能力两点。
      缠丝势每上升一级能延长此招收招时间十秒，增加少许成功率.

HELP
	);
	return 1;
}

 
