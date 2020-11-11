// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
        extra = me->query_skill("yanyu-blade",1);
	if ( extra < 90) return notify_fail("你的雁歌刀法还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［惊天动地］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	msg = HIY  "$N使出雁歌刀法中的【" + HIW"惊天" + HIC"动地" + HIY"】
，一招连环六式，手中的"+ weapon->name()+  "闪电般向$n攻出:\n
                   " + HIG"长" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "       虹" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/damage",extra*4);
        msg = WHT" 惊            贯" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = BLK  "       天                日" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "             动       " NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIR  "                                 地" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/damage",-extra*4);
	me->start_busy(3);
	return 1;
}
