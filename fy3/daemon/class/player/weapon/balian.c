//xgchen@zzfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
 	int orforce;
       object weapon;
	if(me->query("myskill")<8&&me->query("myskill")>10)
		return notify_fail("你现在还没有使用连招的本事！！\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("sword");
        if ( extra < 550) return notify_fail("你的自创剑法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("八剑连招只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
	me->add("force_factor",extra/3);
	orforce = (int) me->query("force");
        me->add("force",extra/3);
	me->add_temp("apply/attack",extra);me->add_temp("apply/damage",extra*2);
       msg = HIR  "\n$N使出自创剑法中的八剑连招，一招连环八剑齐出，手中的"+ weapon->name()+  "闪电般向$n攻出！\n\n"HIW"一剑" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "二剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "三剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "四剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "五剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "六剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIY  "七剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "八剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(4);
	me->set("force_factor",0);
	me->set("force", orforce);
        me->add_temp("apply/attack",-extra);me->add_temp("apply/damage",-extra*2);
        return 1;
}
