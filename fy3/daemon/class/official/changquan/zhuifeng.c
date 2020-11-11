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
    extra = me->query_skill("changquan",1);
    hit = me->query_skill("literate",1);
    damage = me->query_skill("strategy",1);
         if ( extra < 20) return notify_fail("你的少林长拳还不够二十级！\n");
	lv = (int)me->query("zhuifeng");
	if (!lv)
		me->set("zhuifeng",1);
	lv = (int)me->query("zhuifeng");

         if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［追风］只能对战斗中的对手使用。\n");
	orforce = (int) me->query("force");
	if (orforce < lv*20)
		return notify_fail("你的内力不足。\n");
            me->add_temp("apply/attack",hit);
            me->add_temp("apply/damage",damage + lv*100);
	weapon = me->query_temp("weapon");
	me->add("force", -extra/2);
	msg = HIY  "$N长驱直入，一招少林长拳中的［追风］使得淋漓尽致，急如旋风般向$n攻出！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(2);
            me->add_temp("apply/attack",- hit);
            me->add_temp("apply/damage",-damage - lv*100);
	if(me->query("zhuifeng") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("zhuifeng_exp",1);
	      tell_object(me, "你的【追风】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("zhuifeng_exp") > (me->query("zhuifeng")*me->query("zhuifeng")*100))&&(me->query("zhuifeng")< MAX_PFMLEVEL))
		{
		me->add("zhuifeng",1);
		me->set("zhuifeng_exp",0);

	      tell_object(me, HIW"你的【追风】等级上升了。\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n少林长拳之追风："NOR"\n");
	write(@HELP

      此招使用后，单段攻击敌方。

      读书识字技能等级每上升一级，增加此招命中一点。
      兵法技能等级每上升一级，增加此招伤害一点。
      追风等级每上升一级，增加此招伤害一百点。

HELP
	);
	return 1;
}
