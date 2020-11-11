// concentrate.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
        int mana_gain,lv;

        if( target && target!=me )
                return notify_fail("「灵神诀」只能用来恢复自己的法力。\n");

	lv = (int)me->query("concentrate");
	if (!lv)   me->set("concentrate",1);
	lv = (int)me->query("concentrate");

        if(amount == -1) amount = 100;
        else if(amount < 100 ) 
                return notify_fail("最少用一百点内力。\n");

        if( (int)me->query("force") < amount )
                return notify_fail("你的内力不够。\n");

        	if ( random(100)+lv*5 >= 70) 
	{
        mana_gain =  (10 + (int)me->query_skill("gouyee",1))*amount/20;
        if( mana_gain + (int)me->query("mana") > (int)me->query("max_mana") )
                me->set("mana", (int)me->query("max_mana"));
        else
                me->add("mana", mana_gain);
        me->add("force", -amount);
        me->receive_damage("sen", 10);

        message_vision(
                HIY "$N闭目凝神，用谷衣心法的内力运转了一次「灵神诀」...\n"
                "一股青气从$N身上散出，汇聚在$P的顶心，然後缓缓淡去。\n" NOR, me);
			if(me->query("concentrate") < (me->query("level")/10) && userp(me))
		{
		  me->add("concentrate_exp",1);
	      tell_object(me, "你的【灵神诀】获得了一点技能熟练度。\n"NOR);
		  if(me->query("concentrate_exp") > (me->query("concentrate")*me->query("concentrate")*100)&&(me->query("concentrate")<10))
			{
			me->add("concentrate",1);
			me->set("concentrate_exp",0);
			tell_object(me, HIW"你的【灵神诀】熟练上升了。\n"NOR);
			}
		}
	}
	else
		 tell_object(me, "由于不够熟练，你施放的灵神诀失败了。\n"NOR);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}
 int help(object me)
{
        write(YEL"\n谷衣心法之灵神诀："NOR"\n");
	write(@HELP

      灵神诀乃三清宫独门心法，使用后可以恢复少许法力。

      谷衣心法技能等级每上升两级，增加恢复法力五点。
      灵神诀等级每上升一级，增加此招的成功率5%。

HELP
	);
	return 1;
}


