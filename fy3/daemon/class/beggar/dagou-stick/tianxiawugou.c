#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［天下无狗］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
      if( (int)me->query("force") < 100 )     return
        notify_fail("你的内力不够。\n");

	if((int)me->query_skill("dagou-stick",1) < 100)
		return notify_fail("你的打狗棒法还不够精纯！\n");
	extra = me->query_skill("staff") / 7;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N大喝一声［天下无狗］，内力聚于手中的"+ weapon->name() +"，"+
weapon->name() +
"化成满天棍影，昏天黑地般盖向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
      if((int)me->query_skill("dagou-stick",1) > 150)
       msg =HIR  "$N将手中的"+ weapon->name() +"，"+
weapon->name() +
"向$n身后一栏，这叫关门打狗！" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
      if((int)me->query_skill("dagou-stick",1) > 200)
      msg =HIR "$N将手中的"+ weapon->name() +"，"+
weapon->name() +
"指打$n的背心，这叫无路可逃！" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
       me->add("force", -100);
	me->start_busy(2);
	return 1;
}
int help(object me)
{
        write(YEL"\n打狗帮法之天下无狗："NOR"\n");
	write(@HELP

       打狗棒法为洪七公在中原发扬光大丐帮时所创。此套棒法精湛无比，是
       洪七公一生心血的升华。使出打狗棒法的绝招，将手中的打狗棍化成一
       片排山倒海的棍影，虚实相乘，专门敲击敌手的全身各大关节。更有厉害
       的杀招后势。

       要求：	
               (学）无；
               （用）内力 100 以上；
                    打狗棒法等级 100 以上

HELP
	);
	return 1;
}
