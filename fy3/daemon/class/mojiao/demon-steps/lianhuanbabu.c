// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target, int amount)
{
        int skill,lv;

        if( target != me ) return 
	notify_fail("你只能提升自己的暴率。\n");

        if( (int)me->query_temp("lianhuanbabu") ) return 
	notify_fail("你已经在运功中了。\n");
        skill = me->query_skill("demon-steps",1);
	if(skill < 50) return notify_fail("你的天地人魔步法太差了！\n");
	lv = (int)me->query("lianhuanbabu");
	if (!lv)   me->set("lianhuanbabu",1);
	lv = (int)me->query("lianhuanbabu");
        if( (int)me->query("force") < 100*lv )     return notify_fail("你的内力不够。\n");
      	me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(
                HIY 
"$N使出天地人魔连环八步，脚踩连环，变化了八个姿势，瞬间将天地人魔步法发挥到极致！！\n" NOR, me);
        me->add_temp("apply/heavyhit", skill/20);
        me->set_temp("lianhuanbabu", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/20 :), skill/2);
	 me->start_busy(1);
	}
	else 
	{
	write("由于不够熟练，你施放天地人魔连环八步失败了。\n");
	}
	  me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/heavyhit", - amount);
        me->delete_temp("lianhuanbabu");
        tell_object(me,HIG "你的天地人魔连环八步失去效果了，整个人又松懈了下来。\n"NOR);
		if(me->query("lianhuanbabu") < (me->query("level")/10) && userp(me))
	{
	  me->add("lianhuanbabu_exp",1);
	      tell_object(me, "你的【天地人魔连环八步】获得了一点技能熟练度。\n"NOR);
	  if(me->query("lianhuanbabu_exp") > (me->query("lianhuanbabu")*me->query("lianhuanbabu")*100)&&(me->query("lianhuanbabu")<10))
		{
		me->add("lianhuanbabu",1);
		me->set("lianhuanbabu_exp",0);
	      tell_object(me, HIW"你的【天地人魔连环八步】熟练上升了。\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n天地人魔步法之天地人魔连环八步："NOR"\n");
	write(@HELP

      天地人魔步法是魔教的精髓武学。

      天地人魔步法技能等级每上升二十级，增加此招临时暴击点一点。
      天地人魔步法技能等级每增加两级，延长此招的收招时间一秒。
      天地人魔连环八步等级每上升一级，增加此招的成功率5%。

HELP
	);
	return 1;
}
 
