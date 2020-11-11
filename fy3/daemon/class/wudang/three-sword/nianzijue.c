// counterattack.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int lv,skill;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［粘字诀］只能对战斗中的对手使用。\n");
	if (!me->query("nianzijue"))
		me->set("nianzijue",1);
	lv = me->query("nianzijue");
	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
         if( (int)me->query("force") < 50*lv )     return    notify_fail("你的内力不够。\n");
	skill = me->query_skill("three-sword",1);
	msg = CYN "$N使出三才剑法中的「粘」字诀，企图减缓$n的攻势，";

	if( ((random(lv + skill/10))*2 > random(target->query("level"))) && (random(100)>target->query_temp("against"))) {
		msg += "\n结果$p被$P攻了个措手不及！\n" NOR;
		target->start_busy( lv/2 + 1);
	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
            me->add("force", -50*lv);
	if(me->query("nianzijue") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("nianzijue_exp",1);
	      tell_object(me, "你的【粘字诀】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("nianzijue_exp") > (me->query("nianzijue")*me->query("nianzijue")*100))&&(me->query("nianzijue")< MAX_PFMLEVEL))
		{
		me->add("nianzijue",1);
		me->set("nianzijue_exp",0);

	      tell_object(me, HIW"你的【粘字诀】等级上升了。\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n三才剑法粘字诀："NOR"\n");
	write(@HELP

       三才剑法是以太极拳为基础发展而来的加法，和太极拳一样讲究以静制动、
       后发制人，每一招都含着太极式的阴阳变化。粘字诀是也是以太极拳的粘
       字诀为根基，用自己的招式来扰乱敌人，使敌人不可逃跑或出招。
	
      三彩剑法技能等级每上升一级能提高技能成功率。
      粘字诀等级每上升两级能增加对敌方的僵直时间一秒.

HELP
	);
	return 1;
}
