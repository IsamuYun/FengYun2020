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
	lv = (int)me->query("luanpofeng");
	if (!lv)
		me->set("luanpofeng",1);
	lv = (int)me->query("luanpofeng");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
    extra = me->query_skill("pofeng-strike",1);
    hit = me->query_skill("literate",1);
    damage = me->query_skill("str");
         if ( extra < 20) return notify_fail("你的泼风掌还不够二十级！\n");
         if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［乱泼风］只能对战斗中的对手使用。\n");
	orforce = (int) me->query("force");
	if (orforce < lv*30)
		return notify_fail("你的内力不足。\n");
            me->add_temp("apply/attack",hit);
            me->add_temp("apply/damage",damage+lv*130);
	weapon = me->query_temp("weapon");
	me->add("force", lv*30);
	msg = HIR  "$N双掌血红，五指绽开，无数道掌风破空而出，隐隐带着雷声迅疾无比地击向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(2);
            me->add_temp("apply/attack",- hit);
            me->add_temp("apply/damage",-damage - lv*130);
	if(me->query("luanpofeng") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("luanpofeng_exp",1);
	      tell_object(me, "你的【乱泼风】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("luanpofeng_exp") > (me->query("luanpofeng")*me->query("luanpofeng")*100))&&(me->query("luanpofeng")< MAX_PFMLEVEL))
		{
		me->add("luanpofeng",1);
		me->set("luanpofeng_exp",0);

	      tell_object(me, HIW"你的【乱泼风】等级上升了。\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n泼风掌之乱泼风："NOR"\n");
	write(@HELP

      此招使用后，单段攻击敌方。
HELP
	);
	write("\t当前状态：物理命中加成"+(int)(me->query_skill("literate"))+"点,物理伤害加成"+(int)(me->query("str")+me->query("luanpofeng")*130)+"点\n.");
	
	write(@HELP
      读书识字技能等级每上升一级，增加此招命中一点。
      人物力量属性每上升一级，增加此招伤害一点。
      乱泼风等级每上升一级，增加此招伤害一百三十点。

HELP
	);
	return 1;
}
