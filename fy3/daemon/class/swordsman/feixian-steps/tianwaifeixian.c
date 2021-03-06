// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("天外飞仙只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
       if( (int)me->query("force") < 20 )     return
             notify_fail("你的内力不够。\n");
	if (!weapon) return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
	if ( (string) me->query_skill_mapped("sword") != "feixian-sword")
	return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
	extra = me->query_skill("feixian-sword",1) / 10;
	extra += me->query_skill("feixian-steps",1) /10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N脚踏［飞仙步法］，同时使出［飞仙剑法中］的精髓－－天外飞仙，手中的"+ weapon->name() +"划出一道长虹，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "剑光一闪，消失．．．．\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
	msg = HIY "$N身形突转，御剑回飞！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
//        me->add("force", -20);
	me->start_busy(2);
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

       要求：	
               (学）内力 50 以上；
                    内功为净衣心法；
               （用）内力 20 以上；      
                     需要和飞仙剑法配合;

HELP
	);
	return 1;
}
