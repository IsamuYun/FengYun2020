#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("刀神绝技只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("你现在无法施展刀神绝技！\n");
        if( (string)weapon->query("skill_type") != "blade" )
        return notify_fail("你现在无法施展刀神绝技！\n");
        if ( (string) me->query_skill_mapped("blade") != "moon-blade")
        return notify_fail("刀神绝技只能和圆月神刀斩配和！\n");
        extra = me->query_skill("moon-blade",1) / 10;
        extra += me->query_skill("moon-steps",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIR  "\n\n$N使出［圆月神刀斩］中的无上绝技－－刀神！"+ weapon->name() +"划着奇异的弧线，急斩$n！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        for(i=0;i<extra/4;i++)
        {
        msg = CYN "$N御技如神，刀气纵横！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(3);
        return 1;
}
