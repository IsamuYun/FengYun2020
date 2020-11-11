// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill,lv;
      
	lv = (int)me->query("mantianfeixue");
	if (!lv)   me->set("mantianfeixue",1);
	lv = (int)me->query("mantianfeixue");

        if( (int)me->query("force") < 100*lv )     return
        notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("feixue") ) return 
	notify_fail("你已经在施展［漫天飞雪］了。\n");
	skill = me->query_skill_eff_lvl("notracesnow");
	if(skill < 100) return notify_fail("你的踏雪无痕太差了！\n");
	 me->add("force", -100*lv);

	if ( random(100)+lv*5 >= 50) 
	{

        message_vision( HIR
"$N行功运气，身行居然缓缓上升，如风中的雪花！\n" NOR, me);
        me->add_temp("apply/dodge", skill);
        me->set_temp("feixue", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), skill/10+10);
	}
	else 
		return notify_fail("由于不够熟练，你失败了。\n");
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("feixue");
        tell_object(me, "你的［漫天飞雪］施展完毕，身行稳定了下来。\n");
		if(me->query("mantianfeixue") < (me->query("level")/10) && userp(me))
	{
	  me->add("mantianfeixue_exp",1);
	      tell_object(me, "你的【漫天飞雪】获得了一点技能熟练度。\n"NOR);
	  if(me->query("mantianfeixue_exp") > (me->query("mantianfeixue")*me->query("mantianfeixue")*100)&&(me->query("mantianfeixue")<10))
		{
		me->add("mantianfeixue",1);
		me->set("mantianfeixue_exp",0);
	      tell_object(me, HIW"你的【漫天飞雪】熟练上升了。\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n踏雪无痕之漫天飞雪："NOR"\n");
	write(@HELP

      此招使用后可以增加自身的物理闪躲，非战斗状态下可以使用。

      踏雪无痕技能等级每上升一级，增加此招物理闪躲临时点一点。
      踏雪无痕技能等级每增加十级，延长此招的收招时间一秒。
      漫天飞雪等级每上升一级，增加此招的成功率5%。

HELP
	);
	return 1;
}


 
