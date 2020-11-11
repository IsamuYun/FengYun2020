#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,lv,hit;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("天外飞仙只能对战斗中的对手使用。\n");
	lv = me->query("tianwaifeixian");
	if (!lv)  me->set("tianwaifeixian",1);
	lv = me->query("tianwaifeixian");
            if( (int)me->query("force") < 20*lv )     return  notify_fail("你的内力不够。\n");
	hit = me->query_skill("literate",1);
	weapon = me->query_temp("weapon");
	extra = me->query_skill("feixianforce",1) ;
	me->add_temp("apply/attack", hit*lv);	
	me->add_temp("apply/damage", extra/10*lv);
	msg = HIR  "$N使出飞仙剑法中的精髓［天外飞仙］，手中的"+ weapon->name() +"划出一道长虹，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "剑光一闪，消失．．．．\n" NOR;
	message_vision(msg, me, target);
	me->add_temp("apply/attack", -hit*lv);
	me->add_temp("apply/damage", -extra/10*lv);
            me->add("force", -20*lv);
	me->start_busy(2);
	if(me->query("tianwaifeixian") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("tianwaifeixian_exp",1);
	      tell_object(me, "你的【天外飞仙】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("tianwaifeixian_exp") > (me->query("tianwaifeixian")*me->query("tianwaifeixian")*100))&&(me->query("tianwaifeixian")< MAX_PFMLEVEL))
		{
		me->add("tianwaifeixian",1);
		me->set("tianwaifeixian_exp",0);

	      tell_object(me, HIW"你的【天外飞仙】等级上升了。\n"NOR);
		}

	return 1;
}

int help(object me)
{
        write(YEL"\n飞仙剑法之天外飞仙："NOR"\n");
	write(@HELP

       飞仙剑法就是白云城城主－－叶孤城的独门武功。他的剑法不但招式华
       丽无比，而且每式都渗透着武学的真谛。此套剑法，雍容高雅，施展起
       来，就象仙女下凡，载歌载舞，丝毫不给人以拼斗的感觉，不但破绽全
       无，每招都蕴藏着不同的变化，可攻可守，最适合上层社会的人们学习。
       此招突忽其来，如流星，如闪电，如神仙飞来。

     飞仙诀等级每上升十级，各能增加此招的攻击力一点。
      读书识字的等级每上升一级，增加此招的命中一点。
      天外飞仙的等级每上升一级，此招的命中和伤害增加基础值的一倍。

HELP
	);
	return 1;
}