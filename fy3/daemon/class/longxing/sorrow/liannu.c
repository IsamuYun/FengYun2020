//xgchen@zzfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
	int orforce;
        object weapon;
        extra = me->query_skill("tianhuang-sorrow",1);
        if ( extra < 50) return notify_fail("你的[天皇弓]还不够纯熟！\n");
                if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("id") != "baiyu-sorrow" )
                return notify_fail("你必须先装备白羽神箭才能使用[星辉连弩]。\n");
if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［星辉连弩］只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");
        me->add("force_factor",extra/3);
        orforce = (int) me->query("force");
        me->add_temp("apply/attack",extra*extra*50);
me->add_temp("apply/damage",extra*2);
        me->add("force",extra/3);
        msg = MAG  "$N力发肩肘，右手一松，手中的"HIW"白羽神箭"NOR+MAG"化作几道弧光射向$n的$l！\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "$N的"HIW"白羽神箭"HIB"象游龙一般奔向$n的$l！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "$N的"HIW"白羽神箭"HIR"象游龙一般奔向$n的$l！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N的"HIW"白羽神箭"HIY"象游龙一般奔向$n的$l！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "白羽神箭"HIM+BLINK"发出刺耳的破空声,直插在$n的胸口上！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->start_busy(5);
        me->set("force_factor",0);
        me->set("force", orforce);
        me->add_temp("apply/attack",-extra*extra*50);
me->add_temp("apply/damage",-extra*2);
target->apply_condition("throw_poison",random(10)+10);
target->set("prick",1);
        return 1;
}
