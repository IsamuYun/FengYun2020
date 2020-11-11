#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int lvl,lv,hit,dor,damage;
        object weapon;

	lv = me->query("xixuejian");
	if (!lv)  me->set("xixuejian",1);
	lv = me->query("xixuejian");
	weapon = me->query_temp("weapon");
	dor = me->query_skill("dormancy",1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［吸血剑］只能对战斗中的对手使用。\n");

            lvl = (int) me->query_skill("fy-sword",1);
	hit = me->query_skill("literate",1);
	if (me->query("force")< lv*200)
		return notify_fail("你的内力不足!\n");
	msg = MAG  "\n$N的手中的"+weapon->name()+"散发出若隐若现红色光芒，$n的神态映射在了"+weapon->name()+"上！" NOR;
	msg += MAG  "\n$N脸上露出一丝诡异的神色，邪邪地对着"+weapon->name()+"喝到－－收！" NOR;
	me->add("force",-lv*200);
	if (random(lvl/10+hit/10+dor/10) > target->query("level"))
		{
		msg += RED  "\n只见自$n的头顶上而出的一缕红光瞬间被吸入"+weapon->name()+"中！\n" NOR;
		damage = target->query("kee")/10;
		if (damage > lv*5000)
			damage = lv*5000;
		target->receive_damage("kee", damage);
		me ->add("kee",damage/10);
		if (me->query("kee")>me->query("eff_kee"))
			me->set("kee",me->query("eff_kee"));
		}
		else
			msg += RED  "\n只见自$n的头顶上而出的一缕红光又莫名其妙地返回$n的身体中！\n" NOR;
      	            message_vision(msg, me, target);
		me ->start_busy(3);
		if(me->query("xixuejian") < (target->query("level")/10) && !userp(target))
		{
	 		 me->add("xixuejian_exp",1);
			 tell_object(me, "你的【吸血剑】获得了一点技能熟练度。\n"NOR);
		}
		if((me->query("xixuejian_exp") > (me->query("xixuejian")*me->query("xixuejian")*100))&&(me->query("xixuejian")< MAX_PFMLEVEL))
		{
		me->add("xixuejian",1);
		me->set("xixuejian_exp",0);
		tell_object(me, HIW"你的【吸血剑】等级上升了。\n"NOR);
		}
	return 1;
}
int help(object me)
{
        write(YEL"\n大旗风云剑之吸血剑："NOR"\n");
	write(@HELP

      吸血剑此招极为霸道，使出后可以吸取敌方的气血化为己用。
      所谓损人利己的招数。

      读书识字，大旗风云剑，修养术每上升一级，各能增加此招的命中一点。
      吸血剑的等级每上升一级，增加吸取对手的最大气血上限五千。

HELP
	);
	return 1;
}



