// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce,hit,damage,lv;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
            extra = me->query_skill("daode",1);

         if ( extra < 20) return notify_fail("你的道德经还不够二十级！\n");
	if( !me->is_fighting() )
		return notify_fail("［金罡护体］只能在战斗中使用。\n");
	lv = (int)me->query("jinganghuti");
	if (!lv)   me->set("jinganghuti",1);
	lv = (int)me->query("jinganghuti");

	orforce = (int) me->query("force");
	if (orforce < lv*100)
		return notify_fail("你的内力不足。\n");

        if( (int)me->query_temp("daode_dur") )
		 return notify_fail("你已经在运功中了。\n");
      me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(HIG"$N按捏秘诀，周身谈谈而出一圈黄色的光芒！\n" NOR, me);
        me->add_temp("apply/durability", extra/2 + 200*lv);
        me->set_temp("daode_dur", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
extra/2+200*lv :), 10+extra/10);
	  me->start_busy(1);
	}
	else 
	{
	write("由于不够熟练，你施展金罡护体失败了。\n");
	}
	  me->start_busy(2);
        return 1;

}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/durability", - amount);
        me->delete_temp("daode_dur");
        tell_object(me, HIG"你的金罡护体失去效果了。\n"NOR);
		if(me->query("jinganghuti") < (me->query("level")/10) && userp(me))
	{
	  me->add("jinganghuti_exp",1);
	      tell_object(me, "你的【金罡护体】获得了一点技能熟练度。\n"NOR);
	  if(me->query("jinganghuti_exp") > (me->query("jinganghuti")*me->query("jinganghuti")*100)&&(me->query("jinganghuti")<10))
		{
		me->add("jinganghuti",1);
		me->set("jinganghuti_exp",0);
	      tell_object(me, HIW"你的【金罡护体】熟练上升了。\n"NOR);
		}
	}
}
 
int help(object me)
{
        write(YEL"\n道德经之金罡护体："NOR"\n");
	write(@HELP

      道德经是白云城独门学问，只有高深的剑士才能领悟的一项技能。

      道德经技能等级每上升两级，增加此招耐力临时点一点。
      道德经技能等级每增加十级，延长此招的收招时间一秒。
      金罡护体的等级每上升一级，增加此招的成功率5%，以及临时耐力两百点。

HELP
	);
	return 1;
}
