#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,hit,damage,okee,lv;
        object weapon;
        extra = me->query_skill("bloodystrike",1);
        if ( extra < 100) return notify_fail("你的密宗大手印还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
		hit = me->query_skill("bloodystrike",1);
		damage = me->query_skill("bloodystrike",1);
		lv = me->query("fefawubian");
		if (!lv)
			me->set("fefawubian",1);
		lv = me->query("fefawubian");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［佛法无边］只能对战斗中的对手使用。\n");

		if (me->query("force")< lv*100)
			 return notify_fail("你的内力不够。\n");

        me->add_temp("apply/attack",hit*2);
        me->add_temp("apply/damage",damage/10);
		weapon = me->query_temp("weapon");

		me->add("force", -lv*100);
        msg = HIR "$N使出密宗大手印中的［佛法无边］，幻出无数掌影击向$n！" NOR;

		okee= target->query("kee");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

            me->add_temp("apply/attack",-hit*2);
            me->add_temp("apply/damage",-damage/10);

		if(target->query("kee") < okee && target->query("level")<extra/10)
		{
		message_vision(HIB"$N被$n的佛法所封，暂时无法使用任何药品了！\n"NOR,target,me);
		if (!target->query_temp("no_eat"))
			{
       			target->set_temp("no_eat", 1);
				target->remove_call_out("remove_effect");
		        seteuid(ROOT_UID);
			target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 100*lv :), extra/10);
				seteuid(getuid());
			}
		}
	if(me->query("fefawubian") <= (target->query("level")/10) && !userp(target))
		{
	 	 me->add("fefawubian_exp",1);
	      tell_object(me, "你的【佛法无边】获得了一点技能熟练度。\n"NOR);
		}
	  if(me->query("fefawubian_exp") > (me->query("fefawubian")*me->query("fefawubian")*100)&&(me->query("fefawubian")<MAX_PFMLEVEL))
		{
		me->add("fefawubian",1);
		me->set("fefawubian_exp",0);
	      tell_object(me, HIW"你的【佛法无边】等级上升了。\n"NOR);
		}

        me->start_busy(2);
        return 1;
}
void remove_effect(object target, int amount)
{	
        target->delete_temp("no_eat");
        message_vision(HIG"束缚在$N身上的封印好像失效了。\n"NOR,target);
}
int help(object me)
{
        write(YEL"\n密宗大手印之佛法无边："NOR"\n");
	write(@HELP

      此招威力虽为普通，但是特殊效果却能使人瞬间致命。

      密宗大手印技能等级每上升一级，增加此招命中两点，略微提高伤害。
      密宗大手印技能等级每上升十级，延长此招收招一秒。
      佛法无边的等级每上升一级，可以增加对敌有效等级十级。

HELP
	);
	return 1;
}
