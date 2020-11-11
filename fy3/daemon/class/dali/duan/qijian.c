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
        extra = me->query_skill("unarmed")*2;
//        if ( extra > 450) extra = 450;
        if ( extra < 50) return notify_fail("你的段氏一阳指还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［化气为剑］只能对战斗中的对手使用。\n");

        me->add_temp("apply/damage",extra*2);
        me->add_temp("apply/attack",extra/3);
        weapon = me->query_temp("weapon");
        msg = HIR "$N凌空跃起,使出了段氏一阳指的绝技" + HIC "［化气为剑］" HIR + "，食指地向$n点出！\n" NOR;
//        message_vision(msg,me,target);
//        msg = HIY  "━━━━━━━━━━━━━━「化气为剑」！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra/3);
        me->start_busy(2);
        return 1;
}