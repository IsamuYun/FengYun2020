// TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
	string msg;
	int lvl,lv,skill;

//	if(!me->is_fighting())
//	return notify_fail("七星法中的［击星诀］只可以在战斗中施展！\n");
//	if( !target ) target = offensive_target(me);
	if( !target ) target = me;

            if((int)me->query_skill("spells") < 80 )
                return notify_fail("你的法术不够高！\n");
	if (!me->query("jixing"))
		me->set("jixing",1);
	lv = me->query("jixing");
	skill = me->query_skill("qixing",1);
	if (skill < 50)
		return notify_fail("你的七星法还不够等级。\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse() )
	
		return notify_fail("你要对谁施展这个法术？\n");

	if(target->query_temp("in_jixing"))
	return notify_fail("你现在并不需要施展击星诀。\n");

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
            target->add_temp("apply/damage", skill);
            target->set_temp("in_jixing", 1);
	msg +="光芒化成一股力量，注入了$n的全身！\n";
        	seteuid(ROOT_UID);
	target->start_call_out( (: call_other, __FILE__, "remove_jixing",me,target, skill :),
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

void remove_jixing(object me,object target, int lvl)
{
   target->delete_temp("in_jixing");
   target->add_temp("apply/damage",-lvl);
   message_vision(HIY "\n\n$N浑身一闪，似乎有股光茫射出体外。\n\n" NOR, target);
	if(me->query("jixing") < (me->query("level")/10) && userp(me))
	{
	  me->add("jixing_exp",1);
	      tell_object(me, "你的【击星诀】获得了一点技能熟练度。\n"NOR);
	  if(me->query("jixing_exp") > (me->query("jixing")*me->query("jixing")*100)&&(me->query("jixing")<10))
		{
		me->add("jixing",1);
		me->set("jixing_exp",0);
	      tell_object(me, HIW"你的【击星诀】熟练上升了。\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n七星法之击星诀："NOR"\n");
	write(@HELP

      此招可以增加施放目标的临时物理伤害。
	
      七星诀等级每上升一级能提高临时物理伤害一点。
      击星诀每上升一级能延长此招收招时间十秒，增加成功率5%.

HELP
	);
	return 1;
}
