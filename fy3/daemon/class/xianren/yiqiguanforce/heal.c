// heal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if( (int)me->query("force") - (int)me->query("max_force") < 50 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return 
notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        write( HIW "只见你行走之时，开始运功疗伤。\n" NOR);
        message("vision",
                HIW + me->name() + 
"行走之时，脸上一阵红一阵白，不久，吐出一口瘀血，看起来好像在了伤。\n" 
NOR,
                environment(me), me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/2 );
        me->add("force", -50);
        me->set("force_factor", 0);

        return 1;
}
 
