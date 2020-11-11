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
		return notify_fail("［狗急跳墙］只能对战斗中的对手使用。\n");
	if((int)me->query("kee")*8/(int)me->query("max_kee") > 1)
		return notify_fail("你不到万不得以的时候使不出此招！\n");
	weapon = me->query_temp("weapon");
	extra = 2*me->query_skill("doggiesteps",1) / 5;
   me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);
	msg = HIR  "$N凌空一跳，身形如被逼急的野狗，双脚一前一后，狠命地向$n踢出！" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
 me->add_temp("apply/damage", -extra);
   me->add_temp("apply/attack", -extra);
	me->start_busy(2);
	return 1;
}

int help(object me)
{
        write(YEL"\n野狗步法之狗急跳墙："NOR"\n");
	write(@HELP

       野狗步法据说是丐帮鼻祖乌鲁汉自创此步法，并且以此步法横行塞外。
       此步法后经丐帮历代帮主研究发展，不仅是一等一的步法，同时在步法
       施展时，能够出腿进攻。这招狗急跳墙却是第六代帮驻卯金刀，在一次
       看到追杀伤人的野狗时，看到被自己追杀即将毙命时的反扑，有所感悟
       创出来的。

       要求：	
               (学）无；
               （用）自己气血不足平时的1/8时；

HELP
	);
	return 1;
}
