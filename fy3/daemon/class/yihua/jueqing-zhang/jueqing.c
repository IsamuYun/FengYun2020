//xgchen@fy
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
                return notify_fail("［绝情绝义］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        extra = me->query_skill("jueqing-zhang",1) ;
        if ((int)me->query_skill("mingyu-shengong", 1) < 150)
                return notify_fail("你的明玉神功火候太浅。\n");
        if( extra <=20) return notify_fail("你的[绝情拳]还不够熟练！\n");
        if( me->query("class")!="yihua") return notify_fail("你的[绝情拳]已失去威力了！\n");
      if( (int)me->query("force") < 2400 )     return
        notify_fail("你的内力不够。\n");
        me->add_temp("apply/attack", extra/5);  
        me->add_temp("apply/damage", extra/5);
        msg = HIW  "\n$N你施展绝情的绝招 "+HIR"[无情无义]"+NOR+HIW" 向$n攻击！"+NOR+WHT"\n\n$N双掌交错,一招"+NOR+HIB"「无情」"+NOR+WHT"，左掌虚探，右掌聚力拍向$n的头部!" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
            if( extra >160) {
            me->add_temp("apply/attack", extra/5);
            me->add_temp("apply/damage", extra/5);
       msg = WHT  "$N凝神聚气，一招"+NOR+HIB"「无义」"NOR+WHT"，掌风如细雨般向$n的$l扫去！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
            me->add_temp("apply/attack", -extra/5);
           me->add_temp("apply/damage", -extra/5);
            }
            if( extra >220) {
       me->add_temp("apply/attack", extra*extra/5);
            me->add_temp("apply/damage", extra);
            msg = WHT  "$N一招"+NOR+HIB"「无泪」"+NOR+WHT"，双掌幻化为一片花影，将$n笼罩于花影之内！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       me->add_temp("apply/attack", -extra*extra/5);
        me->add_temp("apply/damage", -extra);
       }
            if( extra >380) {
       me->add_temp("apply/attack", extra*extra/5);
            me->add_temp("apply/damage", extra*extra);
            msg = WHT  "$N身形凌空飞起，一招"NOR+HIB"「无痕」"NOR+WHT"，向$n的$l连击数掌！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       me->add_temp("apply/attack", -extra*extra/5);
        me->add_temp("apply/damage", -extra*extra);
       }
            if( extra >600) {
       me->add_temp("apply/attack", extra*extra);
            me->add_temp("apply/damage", extra*extra);
        me->add("str",extra);           
 msg = HIW  "$N双目发出恐怖的蓝光，绝情掌的至柔至刚的"BLINK+HIB"「无情无义」"NOR+HIW"，向$n的全身攻去！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       me->add_temp("apply/attack", -extra*extra);
        me->add_temp("apply/damage", -extra*extra);
           me->add("str",-extra);       
}
       me->add_temp("apply/attack", -extra/5);
        me->add_temp("apply/damage", -extra/5);
        me->start_busy(4);
        return 1;
}int help(object me)
{
        write(RED"\n绝情绝义掌："NOR"\n");
        write(@HELP

        该掌是邀月宫主成名之学,由她自创而成的掌法，使用出来，
        会使人仿佛身中无情一击，痛苦不堪，杀伤力甚是巨大！而
             且此攻击力高，不过学习的难度大。

        要求：  绝情绝义等级 160 以上

HELP
        );
        return 1;
}


