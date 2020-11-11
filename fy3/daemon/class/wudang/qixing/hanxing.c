// TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
	string msg,ob_name;
	int lvl,lv,skill;

//	if(!me->is_fighting())
//	return notify_fail("七星法中的［捍星诀］只可以在战斗中施展！\n");
//	if( !target ) target = offensive_target(me);

	if( !target ) target = me;

            if((int)me->query_skill("spells") < 80 )
                return notify_fail("你的法术不够高！\n");
	if (!me->query("hanxing"))
		me->set("hanxing",1);
	lv = me->query("hanxing");
	skill = me->query_skill("qixing",1);
	if (skill < 50)
		return notify_fail("你的七星法还不够等级。\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse() )
	
		return notify_fail("你要对谁施展这个法术？\n");

	if(target->query_temp("in_hanxing"))
	return notify_fail("你现在并不需要施展捍星诀。\n");

	if((int)me->query("mana") < 300 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("mana", -300);
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 300 ) {
		write("你失败了！\n");
		return 1;
	}
	msg = HIC "$N口中念念有词，一道光芒从$N头顶射出，缭绕在$n周围！\n\n" ;
	if ( random(100)+lv*5 >= 50) 
	{
            target->add_temp("apply/defense", skill);
            target->set_temp("in_hanxing", 1);
	msg +="光芒化成一身护甲，注入了$n的全身！\n";
        	seteuid(ROOT_UID);
	target->start_call_out( (: call_other, __FILE__, "remove_hanxing",me,target, skill :),
	 lv*10+10);
	seteuid(getuid());
	me->start_busy(2);
	} else
		msg += "但是马上就消失了。\n";
	if(me == target) 
	{
	msg = replace_string(msg, "$n","$N");
	message_vision(msg+NOR,me);
	}
	else
	message_vision(msg+NOR, me, target);
	return 1;
}

void remove_hanxing(object me,object target, int lvl)
{
   target->delete_temp("in_hanxing");
   target->add_temp("apply/defense",-lvl);
   message_vision(HIY "\n\n$N浑身一闪，似乎有股光茫射出体外。\n\n" NOR, target);
   			if(me->query("hanxing") < (me->query("level")/10) && userp(me))
	{
	  me->add("hanxing_exp",1);
	      tell_object(me, "你的【捍星诀】获得了一点技能熟练度。\n"NOR);
	  if(me->query("hanxing_exp") > (me->query("hanxing")*me->query("hanxing")*100)&&(me->query("hanxing")<10))
		{
		me->add("hanxing",1);
		me->set("hanxing_exp",0);
	      tell_object(me, HIW"你的【捍星诀】熟练上升了。\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n七星法之捍星诀："NOR"\n");
	write(@HELP

      此招可以增加施放目标的临时物理防御。
	
      七星诀等级每上升一级能提高临时物理防御一点。
      捍星诀每上升一级能延长此招收招时间十秒，增加成功率5%.

HELP
	);
	return 1;
}

