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
        extra = me->query_skill("unarmed");
        if ( extra < 100) return notify_fail("你的野球拳还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［野球拳］只能对战斗中的对手使用。\n");
        me->add("force_factor",extra/5);
        orforce = (int) me->query("force");

        me->add("force",extra/5*150);
        me->add_temp("apply/attack",extra/10);
        weapon = me->query_temp("weapon");
        msg = HIY  "$N使出风云主人自创的［野球拳］，连连向$n打去！\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "一拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "二拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "三拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = GRN  "四拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC  "五拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIB  "六拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = MAG  "七拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = BLK  "无影神拳！" NOR;

        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(5);
        me->set("force_factor",0);
        me->set("force", orforce);
        me->add_temp("apply/attack",-extra/10);
        return 1;
}