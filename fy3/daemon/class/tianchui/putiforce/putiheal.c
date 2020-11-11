// lifeheal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
	int lv,lv2;
	lv = me->query("putiheal");
	if (!lv)
		me->set("putiheal",1);
	lv = (int)me->query("putiheal");
	lv2 = me->query_skill("putiforce",1);
	if( me->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if( (int)me->query("force") - (int)me->query("max_force") < 150*lv )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 5 )
		return notify_fail( "你已经受伤过重，经受不起你的真气震荡！\n");

	message_vision(
		HIY "$N坐了下来运起内功，脸上一阵红一阵白，不久，吐出一口瘀血，脸色看起来好多了。\n"
		"过了不久，$N额头上冒出豆大的汗珠，吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me);

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/3*lv+lv2/10 );
	me->add("force", -150*lv);
	me->set("force_factor", 0);
		me->add("putiheal_exp",1);
	    tell_object(me, "你的【菩提心境】获得了一点技能熟练度。\n"NOR);
	    if(me->query("putiheal_exp") > (me->query("putiheal")*me->query("putiheal")*100)&&(me->query("putiheal")<10))
		{
		me->add("putiheal",1);
		me->set("putiheal_exp",0);
	      tell_object(me, HIW"你的【菩提心境】熟练上升了。\n"NOR);
		}
	return 1;
}
 int help(object me)
{
        write(YEL"\n菩提心法之菩提心境："NOR"\n");
	write(@HELP
	此招使用后，可以恢复自己的外伤。
HELP
	);
	  write("\t当前状态：恢复气血伤害"+(int)(me->query_skill("force")/3*me->query("putiheal")+me->query_skill("putiforce",1)/10)+"点\n");
	write(@HELP

      菩提心法等级每上升十级，疗伤的功效增加1点。
      菩提心境等级每上升一级，疗伤的功效增加一倍。

HELP
	);
	return 1;
}

