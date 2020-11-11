// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce,hit,damage;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
    extra = me->query_skill("changquan",1);
    hit = me->query_skill("literate",1);
    damage = me->query_skill("strategy",1);
         if ( extra < 200) return notify_fail("你的少林长拳还不够二百级！\n");
	if (!me->query("yuhuan"))
		me->set("yuhuan",1);
         if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［玉环鸳鸯拳］只能对战斗中的对手使用。\n");
	orforce = (int) me->query("force");
	if (orforce < extra )
		return notify_fail("你的内力不足。\n");
            me->add_temp("apply/attack",hit);
            me->add_temp("apply/damage",damage);
	weapon = me->query_temp("weapon");
	me->add("force", -extra);
	msg = HIY  "$N使出少林长拳中的［玉环鸳鸯拳］，一招连环六式向$n攻出！\n" NOR;

	message_vision(msg,me,target);
	msg = HIY  "上一拳！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "下一拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "左一拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "右一拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "前一拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "后一拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (me->query("yuhuan")>random(10))
		{
		            me->add_temp("apply/damage",damage);
    			msg = HIY  "最后再一拳！！" NOR;
  			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		            me->add_temp("apply/damage",-damage);
		}
	me->start_busy(4);
            me->add_temp("apply/attack",- hit);
            me->add_temp("apply/damage",-damage);
	if(me->query("yuhuan") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("yuhuan_exp",1);
	      tell_object(me, "你的【玉环鸳鸯拳】获得了一点技能熟练度。\n"NOR);
		}

	  if(me->query("yuhuan_exp") > (me->query("yuhuan")*me->query("yuhuan")*100)&&(me->query("yuhuan")<10))
		{
		me->add("yuhuan",1);
		me->set("yuhuan_exp",0);
	      tell_object(me, HIW"你的【玉环鸳鸯拳】等级上升了。\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n少林长拳之玉环鸳鸯拳："NOR"\n");
	write(@HELP

      此招使用后，一招六段攻击敌方，并有几率发动第七段攻击。
      第七段攻击的伤害成翻倍效果。

      读书识字技能等级每上升一级，增加此招命中一点。
      兵法技能等级每上升一级，增加此招伤害一点。
      玉环鸳鸯拳等级每上升一级，增加第七段发动几率10%。

HELP
	);
	return 1;
}
