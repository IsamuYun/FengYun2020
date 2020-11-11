// tiandi@happyfy3
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,lv,hit;
	object weapon;
	lv = me->query("duzhan");
	if (!lv)  me->set("duzhan",1);
	lv = me->query("duzhan");
	hit = me->query_skill("literate",1);
	extra = me->query_skill("ill-quan",1);
	if ( extra < 20) return notify_fail("你的病维摩拳还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［毒战］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	me ->add_temp("apply/attack",hit*lv);
	me ->add_temp("apply/damage",extra);
	msg = MAG  "$N的双拳凝聚出绿色的气团，看上去像带有毒气的烟雾，只听$N嘿嘿一声，朝$n挥去！" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me ->add_temp("apply/attack",-hit*lv);
	me ->add_temp("apply/damage",-extra);
	me->start_busy(2);
	if (random(hit*lv)> target->query_skill("literate",1)) {
		target->apply_condition("commondu",lv*3);
		target->set("statusnow","中毒");
		message_vision("$N沾上了绿色的毒雾！\n",target);
			}
	if(me->query("duzhan") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("duzhan_exp",1);
	      tell_object(me, "你的【毒战】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("duzhan_exp") > (me->query("duzhan")*me->query("duzhan")*100))&&(me->query("duzhan")< MAX_PFMLEVEL))
		{
		me->add("duzhan",1);
		me->set("duzhan_exp",0);

	      tell_object(me, HIW"你的【毒战】等级上升了。\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n病维摩拳之毒战："NOR"\n");
	write(@HELP
     此招在攻击的同时能使你的敌人中毒。
      
     读书识字的等级每上升一级，增加此招的命中一点。
     病维摩拳的等级每上升一级，增加此招的伤害一点。
     毒战每上升一级，增加敌人中毒率以及中毒时间。

HELP
	);
	return 1;
}

