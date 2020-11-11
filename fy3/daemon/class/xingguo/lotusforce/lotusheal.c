// lifeheal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
	int lv,lv2;
	lv = me->query("lotusheal");
	if (!lv)
		me->set("lotusheal",1);
	lv = (int)me->query("lotusheal");
	lv2 = me->query_skill("lotusforce",1);
	if( me->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if( (int)me->query("force") - (int)me->query("max_force") < 150*lv )
		return notify_fail("你的真气不够。\n");

	if (!target || target == me)
		return notify_fail("一片莲心只能对他人使用。\n");

	message_vision(
		HIY "$N坐了下来运起内功，双手搭在$n的背后开始疗伤，同时周身出现一片莲花，仿似观音现世一般。\n"
		"过了不久，$n额头上冒出豆大的汗珠，吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me,target);

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/2*lv+lv2/10 );
	me->add("force", -150*lv);
	me->set("force_factor", 0);
		me->add("lotusheal_exp",1);
	    tell_object(me, "你的【一片莲心】获得了一点技能熟练度。\n"NOR);
	    if(me->query("lotusheal_exp") > (me->query("lotusheal")*me->query("lotusheal")*100)&&(me->query("lotusheal")<10))
		{
		me->add("lotusheal",1);
		me->set("lotusheal_exp",0);
	      tell_object(me, HIW"你的【一片莲心】熟练上升了。\n"NOR);
		}
	return 1;
}
 int help(object me)
{
        write(YEL"\n莲花心法之一片莲心："NOR"\n");
	write(@HELP
	此招使用后，可以恢复他人的外伤，不可对自己使用。
HELP
	);
	  write("\t当前状态：恢复气血伤害"+(int)(me->query_skill("force")/2*me->query("lotusheal")+me->query_skill("lotusforce",1)/10)+"点\n");
	write(@HELP

      莲花心法等级每上升十级，疗伤的功效增加1点。
      一片莲心等级每上升一级，疗伤的功效增加一倍。

HELP
	);
	return 1;
}

