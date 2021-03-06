// chillgaze.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target, int amount)
{
        object *ob;
        int i, skill, damage;

        if( !me->is_fighting() )
                return notify_fail("［瘴气术］只能在战斗中使用。\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("你的内力不够。\n");

        if( !target || target==me ) {
                target = offensive_target(me);
                if( !target) return notify_fail("你要对谁施展［瘴气术］？\n");

        }

        skill = me->query_skill("force");

        me->add("force", -50);
        me->receive_damage("sen", 20);

        message_vision(
                HIB "\n$N气运丹田，将体内的毒素运到口中，猛的向$n喷去！\n" NOR, me, target);
        
        if( random(target->query("combat_exp")) > (int)me->query("combat_exp") / 2 ) {
                message_vision("$N见势不妙，侧向跳开避开了$n喷的毒气。\n", target, me);
                me->start_busy(3);
                return 1;
        }

        damage = (int)me->query("force_factor") * 2 - target->query("max_force") / 15;
        if( damage < 1 ) {
                message_vision("但是$N对$n喷出的毒气视若无睹....。\n", target, me);
                me->start_busy(3);

                return 1;
        }

        target->receive_damage("gin", damage);
        if( random(skill) > (int)target->query("cps") * 2 )
        target->apply_condition("zhangdu",random(10)+3);
                target->start_busy(3);
        message_vision("$N被$n的毒气喷中，不觉得一阵眩晕，$N已经中了瘴气奇毒了。\n", target, me);
        
        me->start_busy(1);
        return 1;
}
