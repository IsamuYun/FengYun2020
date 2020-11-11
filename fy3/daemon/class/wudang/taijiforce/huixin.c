// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill,lv;

        if( target != me ) return 
	notify_fail("你只能对自己使用慧心诀。\n");

        if( (int)me->query_temp("huixin") ) return 
	notify_fail("你已经在运功中了。\n");
        skill = me->query_skill("taijiforce",1);
	if(skill < 20) return notify_fail("你的太极心法太差了！\n");
	lv = (int)me->query("huixin");
	if (!lv)   me->set("huixin",1);
	lv = (int)me->query("huixin");
        if( (int)me->query("force") < 100*lv )     return notify_fail("你的内力不够。\n");
      	me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(
                HIY 
"$N汇聚天地万物之灵气于一身，进入了海纳于心的状态！\n" NOR, me);
        me->add_temp("apply/karma", skill/10);
        me->set_temp("huixin", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/10 :), skill/2);
	 me->start_busy(1);
	}
	else 
	{
	write("由于不够熟练，你施放慧心诀失败了。\n");
	}
	  me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/karma", - amount);
        me->delete_temp("huixin");
        tell_object(me,HIG "你的慧心诀失去效果了，整个人又松懈了下来。\n"NOR);
		if(me->query("huixin") < (me->query("level")/10) && userp(me))
	{
	  me->add("huixin_exp",1);
	      tell_object(me, "你的【慧心诀】获得了一点技能熟练度。\n"NOR);
	  if(me->query("huixin_exp") > (me->query("huixin")*me->query("huixin")*100)&&(me->query("huixin")<10))
		{
		me->add("huixin",1);
		me->set("huixin_exp",0);
	      tell_object(me, HIW"你的【慧心诀】熟练上升了。\n"NOR);
		}
	}
}
 
int help(object me)
{
        write(YEL"\n太极心法之慧心诀："NOR"\n");
	write(@HELP

      此招为太极心法的基础，使用后增加自身临时运气。
	
      太极心法技能等级每上升十级，增加临时运气一点。
      太极心法技能等级每上升两级，延长此招收招时间一秒。
      慧心诀等级每上升一级，增加技能成功率5%.
HELP
	);
	return 1;
}

