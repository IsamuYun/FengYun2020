#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        extra = me->query_skill("dayusword",1);
        if ( extra < 101) return notify_fail("你的［大禹剑法］还不够纯熟！\n");
        extra = me->query_skill("wuwei-force",1);
        if ( extra < 50) return notify_fail("你的［无为心法］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[ 一剑震山河]只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("[ 大禹剑法 ]只能用剑使用！\n");
        extra = me->query_skill("dayusword",1) / 5;
        extra += me->query_skill("wuwei-force",1) / 5;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIM  "\n$N强运无为心法,身上的内劲澎湃,脚踏迷步,使出大禹剑法的\n\n"+BLINK+HIR+"\t一剑震山河\n"NOR
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "地动山摇．．．．\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIG "漫天飘雨．．．．\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "青山重重．．．．\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIC "水卷万山．．．．\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "乘风破浪．．．．\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIY "剑震山河．．．．\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -extra);   
        me->add_temp("apply/damage", -extra);
        me->start_busy(4);
        return 1;
}


