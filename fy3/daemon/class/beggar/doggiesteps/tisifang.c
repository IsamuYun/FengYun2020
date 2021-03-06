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
		return notify_fail("［踢四方］只能对战斗中的对手使用。\n");
	if((int)me->query("kee")*8/(int)me->query("max_kee") > 1)
		return notify_fail("你不到万不得以的时候使不出此招！\n");
	weapon = me->query_temp("weapon");
	if( (int)me->query("force") < 100 )     return
        notify_fail("你的内力不够。\n");
        if( (int)me->query_skill("doggiesteps",1)<150) return
        notify_fail("你的野狗步法不太纯熟。\n");
	if( (int)me->query("force") < 100 )     return
        notify_fail("你的内力不够！\n");
	if((string) me->query("class") != "beggar" )
		return notify_fail("你不是丐帮的弟子，不能使用「踢四方」。\n");
        extra = me->query_skill("doggiesteps",1) / 20;
        me->add_temp("apply/attack", extra);	
	msg = HIR  "$N身形不动，迅捷无比地向$n向前踢出一腿！" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
	msg = HIR  "$N向左一晃，迅捷无比地向$n向右踢出一腿！" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");	
	msg = HIR  "$N向右一晃，迅捷无比地向$n向左踢出一腿！" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
	msg = HIR  "$N猛一个翻身，迅捷无比地向$n向后踢出一腿！" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
        me->add_temp("apply/attack", -extra);
	me->start_busy(2);
        me->add("force", -100);
	me->start_busy(4);
	return 1;
}

int help(object me)
{
        write(YEL"\n野狗步法之踢四方："NOR"\n");
	write(@HELP

       野狗步法据说是丐帮鼻祖乌鲁汉自创此步法，并且以此步法横行塞外。
       此步法后经丐帮历代帮主研究发展，不仅是一等一的步法，同时在步法
       施展时，能够出腿进攻。这招踢四方意思乃是凭借此步法不仅可以在大
       群野狗之间出入自如，还能扫荡四周，好让野狗无法近身。

       要求：	
               (学）无；
               （用）野狗步法等级 150 以上；
                     内力 100 以上；

HELP
	);
	return 1;
}
