#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,hit,damage,okee,lv;
        object weapon;
        extra = me->query_skill("danei-sword",1);
        if ( extra < 50) return notify_fail("你的大内秘传剑法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
    hit = me->query_skill("danei-sword",1);
    damage = me->query_skill("leadership",1);
	lv = me->query("bajian");
	if (!lv)
		me->set("bajian",1);
	lv = me->query("bajian");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［天下霸剑］只能对战斗中的对手使用。\n");
if (me->query("force")< lv*100)
			 return notify_fail("你的内力不够。\n");

            me->add_temp("apply/attack",hit*2);
            me->add_temp("apply/damage",damage*2);
	weapon = me->query_temp("weapon");
	
	me->add("force", -lv*100);
        msg = HIY  "$N"HIY"使出大内剑法中的［天下霸剑］，手中的"+ weapon->name()+  HIY"挥洒自如，登时$n的四面八方都是剑影，\n此招虚虚实实，令$n方寸大乱！" NOR;

	okee= target->query("kee");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

            me->add_temp("apply/attack",-hit*2);
            me->add_temp("apply/damage",-damage*2);

	if(target->query("kee") < okee)
		{
		message_vision(HIB"$N被$n刺中要害，闪躲能力下降了！\n"NOR,target,me);
		if (!target->query_temp("bajian_minus_dodge"))
			{
       			target->add_temp("apply/dodge", - 100*lv);
        			target->set_temp("bajian_minus_dodge", 1);
			target->remove_call_out("remove_effect");
		        	seteuid(ROOT_UID);
			target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 100*lv :), extra/10);
					seteuid(getuid());
			}
		}
	if(me->query("bajian") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("bajian_exp",1);
	      tell_object(me, "你的【天下霸剑】获得了一点技能熟练度。\n"NOR);
		}
	  if(me->query("bajian_exp") > (me->query("bajian")*me->query("bajian")*100)&&(me->query("bajian")<MAX_PFMLEVEL))
		{
		me->add("bajian",1);
		me->set("bajian_exp",0);
	      tell_object(me, HIW"你的【天下霸剑】等级上升了。\n"NOR);
		}

        me->start_busy(2);
        return 1;
}
void remove_effect(object target, int amount)
{	
        target->add_temp("apply/dodge", amount);
        target->delete_temp("bajian_minus_dodge");
        message_vision(HIG"$N的闪躲能力恢复了。\n"NOR,target);
}
int help(object me)
{
        write(YEL"\n大内剑法之天下霸剑："NOR"\n");
	write(@HELP

      不用说也知道，只有朝廷才能使用的招数，一旦使出，威力比普通攻击要大一倍。
      并且有一定几率可以减低对方的闪躲能力。

      用人之技技能等级每上升一级，增加此招伤害两点。
      大内剑法技能等级每上升一级，增加此招命中两点。
      天下霸剑的等级每上升一级，可以增加对敌降低闪躲能力一百点。

HELP
	);
	return 1;
}
