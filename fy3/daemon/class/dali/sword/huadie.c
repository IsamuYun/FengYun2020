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
                return notify_fail("化蝶只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        extra = me->query_skill("duan-sword",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIG  "$N使出段氏剑法中的精髓［" + HIR"化蝶"HIG + "］，手中的"+ weapon->name() +"划出" + HIC"彩" + HIY"蝶" + HIG"般的曲线击向$n！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);

//      message_vision(msg, me, target);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(3);
        return 1;
}
