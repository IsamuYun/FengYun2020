#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
        int extra,extra1,tmp;
	object weapon;
       if( !target ) target = offensive_target(me);
       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[相思无用]只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("vivien-sword",1);
	if ( extra < 100) return notify_fail("你的[相思剑法]还不够纯熟！\n");
       dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "vivien-steps")
			return notify_fail("［相思无用］需要［忘情步法］的配和！\n");
	tmp = me->query_skill("vivien-steps",1);
        if ( tmp < 80 )return notify_fail("你的［忘情步法］还不够纯熟！\n");
        extra1 = me->query_skill("vivien-sword",1)/5;
        me->add_temp("apply/attack",extra1);   
        me->add_temp("apply/damage",extra1);   
	msg = GRN  "$N使出相思剑法中的最高境界［相思无用］，脑中突然想起了种种，手中的"+ weapon->name()+"化作长虹闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIW "茫茫剑光一现，消失．．．．\n" NOR;
       msg =  WHT "剑光消失，$N突然手中又一亮！" + MAG "\n相思无用第一式：江山一剑！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "剑光消失，$N突然手中又一亮！" + HIM "\n相思无用第二式：海天一剑！" NOR; 
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "剑光消失，$N突然手中又一亮！" + RED "\n相思无用第三式：君子一剑！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "剑光消失，$N突然手中又一亮！" + HIC "\n相思无用第四式：淑女一剑！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "剑光消失，$N突然手中又一亮！" + GRN "\n相思无用第五式：秋水一剑！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "剑光消失，$N突然手中又一亮！" + HIR "\n相思无用第六式：相思一剑！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "剑光消失，$N突然手中又一亮！" + YEL "\n相思无用第七式：无用一剑！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "剑光消失，$N突然手中又一亮！" + BLU "\n相思无用最后一式：相思无用！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->set_temp("apply/attack",-extra1);   
        me->add_temp("apply/damage",-extra1);   
	me->start_busy(4);
	return 1;
}
