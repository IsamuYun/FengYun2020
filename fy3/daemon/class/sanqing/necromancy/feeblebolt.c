// feeblebolt.c

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam,lv;
	if( !target ) target = offensive_target(me);
	 lv = (int)me->query("feeblebolt");
	if (!lv)   me->set("feeblebolt",1);
	lv = (int)me->query("feeblebolt");

        if((int)me->query_skill("spells") < 550 )
                return notify_fail("你的法术不够高！\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展这个法术？\n");

	if((int)me->query("mana") < 155*lv )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("mana", -155*lv);
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("你失败了。\n");
		return 1;
	}
	msg = HIW "$N口中喃喃地念著咒文，左手一挥，手中聚起一团白光射向$n！\n\n" NOR;

	ap = me->query_skill("spells");
	ap += me->query_skill("taoism",1);
	extradam = ap/2;
	dp = target->query("level")*10;
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_mana") / 10 + random((int)me->query("eff_sen") / 10) + random(extradam);
		damage -= (int)target->query("max_mana") / 30 + random((int)target->query("eff_sen") / 15);
		if( damage > 0 ) {
			msg +=  HIR "结果「嗤」地一声，白光从$p身上透体而过，拖出一条长长的黑气直射到\n"
					"两三丈外的地下！\n" NOR;
			target->receive_damage("kee", damage, me);
			target->receive_wound("kee", damage/3*lv+damage, me);
			me->improve_skill("necromancy", 1, 1);
		} else
			msg += "结果「嗤」地一声，白光从$p身上透体而过，无声无息地钻入地下！\n";
	} else
		msg += "但是被$n躲开了。\n";

	message_vision(msg, me, target);
	if( damage > 0 )
		{
		 COMBAT_D->report_status(target);
	if(me->query("feeblebolt") < (target->query("level")/10) && !userp(target))
	{
    	    me->add("feeblebolt_exp",1);
	      tell_object(me, "你的【苍灵之箭】获得了一点技能熟练度。\n"NOR);
	}
	  if(me->query("feeblebolt_exp") > (me->query("feeblebolt")*me->query("feeblebolt")*100)&&(me->query("feeblebolt")<10))
		{
		me->add("feeblebolt",1);
		me->set("feeblebolt_exp",0);
	      tell_object(me, HIW"你的【苍灵之箭】熟练上升了。\n"NOR);
		}
	if (random(100) <lv)
		{
		target->apply_condition("sanqing_drug",random(10)+10);
		target->set("statusnow","晕乎乎");
		message_vision(HIG"$N的苍灵之箭的特殊功效好像在$n身上开始发作了。\n"NOR,me,target);
		}
	}
	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else 				target->kill_ob(me);
		}
		me->kill_ob(target);
	}

	me->start_busy(2);
	return 1;
}
 int help(object me)
{
        write(YEL"\n三清道术之苍灵之箭"NOR"\n");
	write(@HELP

射出一道白色光气攻击敌人，使敌人产
生昏眩的伤害，只有道行高深的法师能体会。

     紫幽之箭每上升一级，伤害效果增加一成，昏眩的几率增加1%。

HELP
	);
	return 1;
}




