// chillgaze.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage,lv;
	lv = (int)me->query("mowuchen");
		if (!lv)   me->set("mowuchen",1);
		lv = (int)me->query("mowuchen");	

	if( !me->is_fighting() )
		return notify_fail("［迷魂大法］只能在战斗中使用。\n");

	if( (int)me->query("force") < 50*lv)
		return notify_fail("你的内力不够。\n");

	if( !target || target==me ) {
		target = offensive_target(me);
		if( !target) return notify_fail("你要对谁施展［迷魂大法］？\n");
	}

	skill = me->query_skill("demon-force",1);

	me->add("force", -50*lv);
	me->receive_damage("sen", 20);

	message_vision(
		HIB "\n$N面上神情诡异，双眼变得异常朦胧！全身的动作缓慢了下来，恍如老牛拖车。\n" NOR, me, target);
	
	if(( (random(lv + skill/10))*2 < random(target->query("level")) ) && (random(100)>target->query_temp("against"))) {
		message_vision("$N很快地转过头去，避开了$n的目光。\n", target, me);
		me->start_busy(3);
		return 1;
	}

	damage = random(skill)  - target->query("level") ;
	if( damage < 100 ) {
		message_vision("但是$N对$n的注视视若无睹....。\n", target, me);
		me->start_busy(3);
		return 1;
	}

	target->receive_damage("kee", damage);
		target->start_busy(3*lv);
	message_vision("$N被$n的诡异神情所惑，不自禁地和$n保持着同样的节奏，慢了下来。\n", target, me);
		me->start_busy(3*lv);
			if(me->query("mihun") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("mihun_exp",1);
	      tell_object(me, "你的【迷魂大法】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("mihun_exp") > (me->query("mihun")*me->query("mihun")*100))&&(me->query("mihun")< 10))
		{
		me->add("mihun",1);
		me->set("mihun_exp",0);

	      tell_object(me, HIW"你的【迷魂大法】等级上升了。\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n天地人魔心法之迷魂大法："NOR"\n");
	write(@HELP

       魔教独闯的武功绝学，能牵制敌方的行动，在群战中作用明显。
	
      天地人魔心法技能等级能提高技能成功率。
      迷魂大法等级每上升一级能增加对敌方的僵直时间三秒，并少许提高技能成功率。

HELP
	);
	return 1;
}

