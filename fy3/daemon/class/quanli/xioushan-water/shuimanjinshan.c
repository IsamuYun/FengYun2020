// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("xioushan-water",1)* 2;
	if ( extra < 100) return notify_fail("你的[秀山引水功]还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[水漫金山]只能对战斗中的对手使用。\n");
	me->add_temp("apply/attack", extra/5);me->add_temp("apply/damage", extra/5);
	
weapon = me->query_temp("weapon");
	msg = HIY  "$N袖中突然打出三道水花，直击$n！第一道！" NOR;
	COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR,msg);
        msg = HIY  "第二道！" NOR;
        COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR,msg);
        msg = HIY  "第三道！" NOR;
        COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR,msg);
me->add_temp("apply/attack", -extra/5);me->add_temp("apply/damage", -extra/5);


	me->start_busy(5);
	return 1;
}
