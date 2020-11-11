// heal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if( (int)me->query("force") - (int)me->query("max_force") < 50 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 5 )
                return 
notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
        if( (int)me->query("eff_kee") >= (int)me->query("max_kee"))
                return notify_fail("你没有受伤,不用运功疗伤！\n");

        write( HIM "你盘漆而坐，运起易筋经的无上内功开始运功疗伤。\n" NOR);
        message("vision",
                HIM + me->name() + 
"易筋无上真气在你筋络游走，不久，他的内伤迅速得到好转。\n"NOR,
                environment(me), me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/2 );
        me->add("force", -50);
        me->set("force_factor", 0);

        return 1;
}
 
