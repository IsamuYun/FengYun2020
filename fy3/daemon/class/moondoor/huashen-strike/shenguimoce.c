#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［神鬼莫测］只能对战斗中的对手使用。\n");
        extra = me->query_skill("unarmed")* 2 ;
        if(extra <= 80 ) return notify_fail("你的［化神掌法］不够熟练！\n");
        msg = HIR "$N左掌击在右掌上,两掌相交,幻出无数掌影罩向$n的全身！" NOR;
        weapon = me->query_temp("weapon");
        me->add_temp("apply/damage",extra*2);
        me->add_temp("apply/attack",extra);

        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
        me->start_busy(2);
        return 1;
}