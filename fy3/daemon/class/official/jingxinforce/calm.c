
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
      int skill,lv;
	skill = me->query_skill("jingxinforce",1) ;

      if( target != me ) return notify_fail("你只能提升自己的定力。\n");
	if(skill < 10)
		return notify_fail("你的静心心法等级太低。\n");
	lv = (int)me->query("calm");
	if (!lv)   me->set("calm",1);
	lv = (int)me->query("calm");

      if( (int)me->query("force") < (lv*100) )
	       return notify_fail("你的内力不够。\n");


        if( (int)me->query_temp("jingxin_calm") )
		 return notify_fail("你已经在运功中了。\n");
      me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(HIG"$N聚气定神，全身忽然觉得一阵轻松！\n" NOR, me);
        me->add_temp("apply/composure", skill/10);
        me->set_temp("jingxin_calm", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/10 :), skill/2);
	  me->start_busy(1);
	}
	else 
	{
	write("由于不够熟练，你施放定神诀失败了。\n");
	}
	  me->start_busy(2);
        return 1;

}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/composure", - amount);
        me->delete_temp("jingxin_calm");
        tell_object(me, HIG"你的定神诀失去效果了。\n"NOR);
			if(me->query("calm") < (me->query("level")/10) && userp(me))
	{
	  me->add("calm_exp",1);
	      tell_object(me, "你的【定神诀】获得了一点技能熟练度。\n"NOR);
	  if(me->query("calm_exp") > (me->query("calm")*me->query("calm")*100)&&(me->query("calm")<10))
		{
		me->add("calm",1);
		me->set("calm_exp",0);
	      tell_object(me, HIW"你的【定神诀】熟练上升了。\n"NOR);
		}
	}
}
 int help(object me)
{
        write(YEL"\n静心心法之定神诀："NOR"\n");
	write(@HELP

      定神诀使用后，可以增加自身的临时定力。

      静心心法技能等级每上升十级，增加此招定力临时点一点。
      定神决的等级每上升一级，增加此招的成功率5%。

HELP
	);
	return 1;
}

