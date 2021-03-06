// tie@fengyun

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
                return notify_fail("［野球拳］只能对战斗中的对手使用。\n");
        extra = me->query_skill("unarmed")* 5 ;
        if(extra <= 300 ) return notify_fail("你的［野球拳］不够熟练！\n");
        COMBAT_D->do_attack(me,target, 
        me->query_temp("weapon"),TYPE_REGULAR,msg);

weapon = me->query_temp("weapon");
        me->add_temp("apply/damage",extra*10);
        me->add_temp("apply/attack",extra/3);
        msg = HIR "$N突然从身后伸出双手，大喝一声：连连向$n打去！\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "石头！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "剪子！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "布！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       
        me->add_temp("apply/damage",-extra*10);
        me->add_temp("apply/attack",-extra/3);
        me->start_busy(2);
        return 1;
}