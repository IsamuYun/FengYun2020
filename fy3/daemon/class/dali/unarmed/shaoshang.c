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
        if ( extra < 120) return notify_fail("你的六脉神剑还不够纯熟！\n");
        if( (int)me->query("force") < 50 )     return
        notify_fail("你的内力不够。\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )

                return notify_fail("［ 少商剑 ］只能对战斗中的对手使用。\n");
        me->add("force", -50);
        me->add_temp("apply/damage",extra*2);
        me->add_temp("apply/attack",extra);
        weapon = me->query_temp("weapon");
        msg = HIW  "$N拇指微弹,使出了六脉神剑的「少商剑」，一股剑气带着嘶嘶响声从拇食指发出，刺向$n！\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "━━━━━━━━━━━━━━━━━━━━━━━━「少商剑」！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
        me->start_busy(1);
        return 1;
}