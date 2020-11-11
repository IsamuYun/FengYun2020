// heal.c  written by tiandi

#include <ansi.h>

int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if( (int)me->query("force") - (int)me->query("max_force") < 50 )
                return notify_fail("你的真气不够。\n");
       
        write( HIY "你盘地就坐，气运丹田，途经全身各大要穴，运气一小周天，最后缓缓地纳入丹田。\n" NOR);
        message("vision",
                HIY + me->name() + 
"盘地就坐，气运丹田，途经全身各大要穴，运气一小周天，最后缓缓地纳入丹田。\n"
+RED+"不久"+ me->name() + "吐出一口"+HIR+"瘀血，脸色看起来好多了。\n" 
NOR,
                environment(me), me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/2 );
        me->add("force", -50);
        me->set("force_factor", 0);

        return 1;
}
 
