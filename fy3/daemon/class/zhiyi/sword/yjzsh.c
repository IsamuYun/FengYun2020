// by xgchen
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int ff;
            object weapon;
         ff = me->query("force");
       extra = me->query_skill("dayusword",1);
         if ( ff < 1500) return notify_fail("你的内力不够！\n");
       if ( extra < 101) return notify_fail("你的［大禹剑法］还不够纯熟！\n");
        dodskill = (string) me->query_skill_mapped("force");
        if ( dodskill != "wuwei-force")
                        return notify_fail("［大禹剑法］需要有［无为心法］的配合！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［一剑震山河］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
              msg = HIM  "\n$N强运无为心法,身上的内劲澎湃,脚踏迷步,使出大禹剑法的"
         +BLINK+HIY+"\n\n\t   <<|| 一  剑  震  山  河 ||>>"+NOR+"\n
    \n"+HIW+"\t\t［地动山摇］\n$N手中剑向$n攻去！" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
              msg = HIG  "\n\t\t［八方风雨］\n$N手中剑向$n攻去！" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIY  "\n\t\t［巨浪汹涌］\n$N手中剑向$n攻去！" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIB  "\n\t\t［青山重重］\n$N手中剑向$n攻去！" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIG  "\n\t\t［水卷山脉］\n$N手中剑向$n攻去！" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIW  "\n\t\t［金光四射］\n$N手中剑向$n攻去！" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIC  "\n\t\t［剑气冲天］\n$N手中剑向$n攻去！" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIR  "\n\t\t［剑震山河］\n$N手中的剑慢慢变红,发出强烈的气流围着$n！" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        me->start_busy(5);


   target->receive_damage("kee", extra*10);
   target->receive_wound("kee", extra*5);
   me->add("force", -200);
        return 1;
}
