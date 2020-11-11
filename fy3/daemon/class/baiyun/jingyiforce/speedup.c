// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill,lv;

        if( target != me ) return 
	notify_fail("你只能提升自己的速度。\n");

        if( (int)me->query_temp("speedup") ) return 
	notify_fail("你已经在运功中了。\n");
        skill = me->query_skill("jingyiforce");
	if(skill < 20) return notify_fail("你的净衣心法太差了！\n");
	lv = (int)me->query("speedup");
	if (!lv)   me->set("speedup",1);
	lv = (int)me->query("speedup");
        if( (int)me->query("force") < 100*lv )     return notify_fail("你的内力不够。\n");
      	me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(
                HIR 
"$N暗暗地聚气凝神，整个人处于一触即发的状态！\n" NOR, me);
        me->add_temp("apply/agility", skill/10);
        me->set_temp("speedup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/10 :), skill/2);
	 me->start_busy(1);
	}
	else 
	{
	write("由于不够熟练，你施放急进失败了。\n");
	}
	  me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/agility", - amount);
        me->delete_temp("speedup");
        tell_object(me,HIG "你的急进失去效果了，整个人又松懈了下来。\n"NOR);
		if(me->query("speedup") < (me->query("level")/10) && userp(me))
	{
	  me->add("speedup_exp",1);
	      tell_object(me, "你的【急进】获得了一点技能熟练度。\n"NOR);
	  if(me->query("speedup_exp") > (me->query("speedup")*me->query("speedup")*100)&&(me->query("speedup")<10))
		{
		me->add("speedup",1);
		me->set("speedup_exp",0);
	      tell_object(me, HIW"你的【急进】熟练上升了。\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n净衣心法之急进："NOR"\n");
	write(@HELP

      净衣心法是白云城心法的基础。

      净衣心法技能等级每上升十级，增加此招速度临时点一点。
      净衣心法技能等级每增加两级，延长此招的收招时间一秒。
      急进等级每上升一级，增加此招的成功率5%。

HELP
	);
	return 1;
}
 
