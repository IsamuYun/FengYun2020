// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,hit,damage,lv;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("天外飞仙只能对战斗中的对手使用。\n");
	lv = me->query("tianwaifeixian");
	if (!lv)  me->set("tianwaifeixian",1);
	lv = me->query("tianwaifeixian");
	weapon = me->query_temp("weapon");
            if( (int)me->query("force") < 50*lv )     return  notify_fail("你的内力不够。\n");
	if (!weapon) return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
	if ( (string) me->query_skill_mapped("sword") != "feixian-sword")
	return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
	hit = me->query_skill("literate",1) ;
	damage = me->query_skill("feixian-steps",1) /10;
	damage += me->query_skill("feixian-sword",1) /10;
	damage += me->query_skill("feixianforce",1) /10;
	me->add_temp("apply/attack", hit);	
	me->add_temp("apply/damage", damage);
	msg = HIR  "$N脚踏［飞仙步法］，同时使出［飞仙剑法中］的精髓－－天外飞仙，手中的"+ weapon->name() +"划出一道长虹，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "剑光一闪，消失．．．．\n" NOR;
            message_vision(msg, me, target);
	for(i=0;i<lv;i++)
	{
	msg = HIY "$N身形突转，御剑回飞！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -hit);
	me->add_temp("apply/damage", -damage);
            me->add("force", -50*lv);
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
        write(YEL"\n飞仙步法之天外飞仙："NOR"\n");
	write(@HELP

       飞仙步法就是白云城城主－－叶孤城的独门武功。主要是为了配合飞仙
       剑法而创立的，此步法雍容高雅，施展起来，就象仙女下凡，载歌载舞，
       丝毫不给人以拼斗的感觉，和飞仙剑法配合不但破绽全无，而且威力增
       强数倍。

      飞仙步法，飞仙剑法，飞仙诀等级每上升十级，各能增加此招的攻击力一点。
      读书识字的等级每上升一级，增加此招的命中一点。
      天外飞仙的等级每上升一级，增加一次御剑回飞。

HELP
	);
	return 1;
}
