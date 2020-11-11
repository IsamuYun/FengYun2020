// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        object weapon;
        extra = me->query_skill("qingshe-sword",1);
        if ( extra < 50) return notify_fail("你的［青蛇剑法］还不够纯熟！\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "wudu-steps")
                        return notify_fail("［千蛇出洞］需要［五毒步法］的配和！\n");
        tmp = me->query_skill("wudu-steps",1);
        if ( tmp < 50 )return notify_fail("你的［五毒步法］还不够纯熟！\n");
        
        if( !target ) target = offensive_target(me);
        if( !target

        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［千蛇出洞］只能对战斗中的对手使用。\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        msg = HIR  "\n\n$N手中的$w幻出千朵剑花使出青蛇剑法的不传绝学 ---千-蛇-出-洞--- ！！\n\n\n青蛇欲探头！\n$N手中$w直刺$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "青蛇微吐芯！\n$N手中$w斜刺$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "青蛇翻身搏！\n$N手中$w横刺$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "青蛇啮八方！\n$N手中$w猛刺$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "青蛇云里游！\n$N手中$w反撩$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(4);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;

}