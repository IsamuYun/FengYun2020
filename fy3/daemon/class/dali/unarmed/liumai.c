// mouse@skills
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int orforce;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill("liumaishenjian",1);
        if ( extra < 150) return notify_fail("你的六脉神剑还不够纯熟！\n");
        if( (int)me->query("force") < 100 )     return
        notify_fail("你的内力不够。\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )

                return notify_fail("［六脉归宗］只能对战斗中的对手使用。\n");
        me->add_temp("apply/damage",extra*3);
        me->add_temp("apply/attack",extra);
        me->add("force", -100);
        weapon = me->query_temp("weapon");
        msg = HIR  "$N凌空跃起,使出了六脉神剑的最高绝技「" + HIC "六脉归宗" + HIR "」，十指连绵不绝地向$n点出！\n" NOR;
        message_vision(msg,me,target);

        msg = HIG  "\n  「少泽剑」！\n" NOR;

        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "\n      「关冲剑」！\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "\n          「商阳剑」！\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "\n              「少冲剑」！\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "\n                  「中冲剑」！\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "\n                      「少商剑」！\n" NOR;

        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*3);
        me->add_temp("apply/attack",-extra);
        me->start_busy(3);
        return 1;
}