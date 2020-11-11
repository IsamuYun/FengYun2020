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
                return notify_fail("化蝶对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("化蝶只能和段氏剑法配和！\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("化蝶只能和段氏剑法配和！\n");
        if ( (string) me->query_skill_mapped("sword") != "duan-sword")

        return notify_fail("化蝶只能和段氏剑法配和！\n");
        extra = me->query_skill("duan-sword",1) / 10;
        extra += me->query_skill("duan-steps",1) /10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIG  "$N脚踏［段氏步法］，同时使出［段氏剑法］中的精髓－［" + HIR"化蝶"HIG + "］，手中的"+ weapon->name() +"划出" + HIC"彩" + HIY"蝶" + HIG"般的曲线击向$n！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//      msg =  HIW "剑光一闪，消失．．．．\n" NOR;
//      message_vision(msg, me, target);
        for(i=0;i<extra/4;i++)
        {
//      msg = HIG  "$N脚踏［段氏步法］，同时使出［段氏剑法］中的精髓－－［" + HIR"化蝶"HIG + "］，手中的"+ weapon->name() +"划出" + HIC"彩" + HIY"蝶" + HIG"般的曲线击向$n！" NOR;
//      message_vision(msg, me, target);
        msg = HIC "$N身形如彩蝶飞舞，又出一剑！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(2);
        return 1;

}