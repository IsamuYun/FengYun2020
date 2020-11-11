// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce,hit,damage,lv;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
            extra = me->query_skill("liuyun-steps",1);

         if ( extra < 20) return notify_fail("你的流云步法还不够二十级！\n");
	if( !me->is_fighting() )
		return notify_fail("［行云流水］只能在战斗中使用。\n");
	lv = (int)me->query("xingyunliushui");
	if (!lv)   me->set("xingyunliushui",1);
	lv = (int)me->query("xingyunliushui");

	orforce = (int) me->query("force");
	if (orforce < lv*100)
		return notify_fail("你的内力不足。\n");

        if( (int)me->query_temp("liuyun_dodge") )
		 return notify_fail("你已经在运功中了。\n");
      me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(HIG"$N骤然间变得仿似天上漂浮的云，河里流动的水一般初无定质！\n" NOR, me);
        me->add_temp("apply/dodge", extra/2);
        me->set_temp("liuyun_dodge", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
extra/2 :), 10+extra/10);
	  me->start_busy(1);
	}
	else 
	{
	write("由于不够熟练，你施展行云流水失败了。\n");
	}
	  me->start_busy(2);
        return 1;

}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("liuyun_dodge");
        tell_object(me, HIG"你的行云流水失去效果了。\n"NOR);
			if(me->query("xingyunliushui") < (me->query("level")/10) && userp(me))
	{
	  me->add("xingyunliushui_exp",1);
	      tell_object(me, "你的【行云流水】获得了一点技能熟练度。\n"NOR);
	  if(me->query("xingyunliushui_exp") > (me->query("xingyunliushui")*me->query("xingyunliushui")*100)&&(me->query("xingyunliushui")<10))
		{
		me->add("xingyunliushui",1);
		me->set("xingyunliushui_exp",0);
	      tell_object(me, HIW"你的【行云流水】熟练上升了。\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n流云步法之行云流水："NOR"\n");
	write(@HELP

      流云步法是朝廷独闯的步法，此招使用后可以增加自身的物理闪躲。

      流云步法技能等级每上升两级，增加此招物理闪躲临时点一点。
      流云步法技能等级每增加十级，延长此招的收招时间一秒。
      行云流水等级每上升一级，增加此招的成功率5%。

HELP
	);
	return 1;
}

