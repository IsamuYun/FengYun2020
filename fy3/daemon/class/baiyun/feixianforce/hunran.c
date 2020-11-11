// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill,lv;

        if( target != me ) return 
	notify_fail("你只能提升自己的闪避能力。\n");

        if( (int)me->query_temp("hunran") ) return 
	notify_fail("你已经在运功中了。\n");
		if (me->query("hunrantime")-time()>0)
			return notify_fail("不能频繁使用此招，请过会再使用。\n");
        skill = me->query_skill("feixianforce",1);
	if(skill < me->query("level")*9 ) return notify_fail("你的飞仙诀太差了！\n");
	lv = (int)me->query("hunran");
	if (!lv)   me->set("hunran",1);
	lv = (int)me->query("hunran");
        if( (int)me->query("force") < 500 + 100*lv )     return notify_fail("你的内力不够。\n");
      	me->add("force", -500-100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(
                HIC 
"$N暗捏飞仙诀，双手成菩萨状来回划动与胸前，咻地一声一道护体光环出现在$N周身！\n" NOR, me);
        me->add_temp("apply/dodge",999999 );
        me->set_temp("hunran", 1);
		me->set("hunrantime", (int) time()+ 3600);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
999999 :), 10+lv*6);
	}
	else 
	{
	write("由于不够熟练，你施放浑然天成失败了。\n");
	}
	  me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("hunran");
        tell_object(me,HIG "你的浑然天成去效果了，整个人又松懈了下来。\n"NOR);
		if(me->query("hunran") < (me->query("level")/10) && userp(me))
	{
	  me->add("hunran_exp",1);
	      tell_object(me, "你的【浑然天成】获得了一点技能熟练度。\n"NOR);
	  if(me->query("hunran_exp") > (me->query("hunran")*me->query("hunran")*100)&&(me->query("hunran")<10))
		{
		me->add("hunran",1);
		me->set("hunran_exp",0);
	      tell_object(me, HIW"你的【浑然天成】熟练上升了。\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n飞仙诀之浑然天成："NOR"\n");
	write(@HELP

      飞仙诀的最高境界，瞬间把人提升至物理攻击无敌境界。

      飞仙诀技能等级必须大于人物等级的九倍才可使用此招。
      由于此招太过霸道，所以一小时内只能使用一次。
      浑然天成等级每上升一级，增加此招的成功率5%以及收招时间六秒。

HELP
	);
	return 1;
}
 
