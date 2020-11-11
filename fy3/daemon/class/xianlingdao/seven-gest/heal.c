// heal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
                if(amount<40) amount=40;
        if( (int)me->query("force") < amount )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_skill("seven-gest") < 40 )
                return notify_fail("你的七决剑气太差了，不会使用凝神归元。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 14 )
                return 
                        notify_fail("你已经受伤过重，只怕一运内力便有生命危险！\n");

    if(target==me){
        write( HIC "你使用凝神归元，运功疗伤。\n" NOR);
        message("vision",
                HIW + me->name() + 
                                "使用凝神归元进行治疗，脸色看起来好多了。\n" NOR,
                environment(me), ({ me }));
    }else{
        message_vision( HIR "$N使用凝神归元，为$n运功疗伤，$n的脸色看起来好多了。\n" NOR, me, target);
    }

        target->receive_curing("kee", amount + ((int)me->query_skill("force") * amount /70) );
        target->add("kee", (target->query("eff_kee")-target->query("kee"))/4 );
        me->add("force", -amount);
        me->start_busy(1);

        return 1;
}
