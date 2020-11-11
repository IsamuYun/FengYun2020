// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int hit,damage,lv,orforce;
	object weapon;
	lv = (int)me->query("longxianyuye");
	if (!lv)
		me->set("longxianyuye",1);
	lv = (int)me->query("longxianyuye");
	extra = me->query_skill("buddhism",1);
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［龙现于野］只能对战斗中的对手使用。\n");
	orforce = (int) me->query("force");
	if (orforce < lv*20)
		return notify_fail("你的内力不足。\n");
	me->add("force", -lv*20);
    hit = me->query_skill("literate",1);
    damage = me->query_skill("cloudstaff",1);
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack", hit+lv*100);	
	me->add_temp("apply/damage", damage/2+extra/5);
	msg = HIR  "$N低呼佛号，内力聚于双臂，手中的"+ weapon->name() +HIR"幻出一条金磷飞龙，闪电般的扑向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -hit-lv*100);
	me->add_temp("apply/damage", -damage/2-extra/5);
	me->start_busy(2);
	if(me->query("longxianyuye") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("longxianyuye_exp",1);
	      tell_object(me, "你的【龙现于野】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("longxianyuye_exp") > (me->query("longxianyuye")*me->query("longxianyuye")*100))&&(me->query("longxianyuye")< MAX_PFMLEVEL))
		{
		me->add("longxianyuye",1);
		me->set("longxianyuye_exp",0);

	      tell_object(me, HIW"你的【龙现于野】等级上升了。\n"NOR);
		}

	return 1;
}

int help(object me)
{
        write(YEL"\n白云杖法之龙现于野："NOR"\n");
	write(@HELP

      此招使用后，单段攻击敌方。

      读书识字技能等级每上升一级，增加此招命中一点。
      白云杖法技能等级每上升两级，增加此招伤害一点。
      大乘佛法技能等级每上升五级，增加此招伤害一点。
      龙现于野等级每上升一级，增加此招命中一百点。

HELP
	);
	return 1;
}
