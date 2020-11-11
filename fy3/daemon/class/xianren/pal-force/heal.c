// heal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
                if(amount<50) amount=50;
        if( (int)me->query("force") < amount )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_skill("force") < 50 )
                return notify_fail("你的内功太差了，不会使用元灵归心术。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 10 )
                return 
                        notify_fail("你已经受伤过重，只怕一运内力便有生命危险！\n");

    if(target==me){
        write( HIR "你使用元灵归心术，运功疗伤。\n" NOR);
        message("vision",
                HIW + me->name() + 
                                "使用元灵归心术进行治疗，脸色看起来好多了。\n" NOR,
                environment(me), ({ me }));
    }else{
        message_vision( HIC "$N使用元灵归心术，为$n运功疗伤，$n的脸色看起来好多了。\n" NOR, me, target);
    }

        target->receive_curing("kee", amount + ((int)me->query_skill("force") * amount /50) );
        target->set("kee", (target->query("eff_kee")+target->query("kee"))/2 );
        me->add("force", -amount);

        return 1;
}
