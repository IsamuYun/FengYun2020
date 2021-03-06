// netherbolt.c

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam,lv;

	if( !target ) target = offensive_target(me);
	 lv = (int)me->query("netherbolt");
	if (!lv)   me->set("netherbolt",1);
	lv = (int)me->query("netherbolt");

        if((int)me->query_skill("spells") < 130 )
                return notify_fail("你的法术不够高！\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展这个法术？\n");

	if((int)me->query("mana") < 55*lv )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10*lv )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("mana", -50*lv);
	me->receive_damage("sen", 10*lv);

	if( random(me->query("max_mana")) < 30 ) {
		write("你失败了！\n");
		return 1;
	}

	msg = HIC "$N口中喃喃地念著咒文，左手一挥，手中聚起一团青光射向$n！\n\n" NOR;

	ap = me->query_skill("spells");
	ap += me->query_skill("taoism",1);
	extradam = ap;
	dp = target->query("level")*10;
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("level") * 20 + random((int)me->query("eff_sen") / 20) + random(extradam);
		damage -= (int)target->query("level") * 20 + random((int)target->query("eff_sen") / 20);
		if( damage > 0 ) {
			msg +=  HIR "结果「嗤」地一声，青光从$p身上透体而过，拖出一条长长的血箭直射到\n"
					"两三丈外的地下！\n" NOR;

			target->receive_damage("kee", damage*3, me);
			target->receive_wound("kee", damage/3*lv, me);
			me->improve_skill("necromancy", 1, 1);
	if(me->query("netherbolt") < (target->query("level")/10) && !userp(target))
	{
    	    me->add("netherbolt_exp",1);
	      tell_object(me, "你的【青冥之箭】获得了一点技能熟练度。\n"NOR);
	}
	  if(me->query("netherbolt_exp") > (me->query("netherbolt")*me->query("netherbolt")*100)&&(me->query("netherbolt")<10))
		{
		me->add("netherbolt",1);
		me->set("netherbolt_exp",0);
	      tell_object(me, HIW"你的【青冥之箭】熟练上升了。\n"NOR);
		}

		} else
			msg += "结果「嗤」地一声，青光从$p身上透体而过，无声无息地钻入地下！\n";
	} else
		msg += "但是被$n躲开了。\n";

	message_vision(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(target);

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
        write(YEL"\n三清道术之青冥之箭"NOR"\n");
	write(@HELP

 射出一道青色光气攻击敌人，这个法术
是幽冥三箭中杀伤力较高的一个，随著法力成长而增加的威力也较明显。


     青冥之箭每上升一级，伤害效果增加一成。

HELP
	);
	return 1;
}


