// yiru@hero
// vitalize.c
// 五气朝元

#include <ansi.h>

int exert(object me, object target, int amount)
{
                if(amount<90) amount=90;

        if( (int)me->query("force") < amount )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("atman") < amount )
                return notify_fail("你的灵力不够。\n");
        if( (int)me->query("mana") < amount )
                return notify_fail("你的法力不够。\n");

        if( (int)me->query_skill("shuiyue-xianfa",1) < 120 )
                return notify_fail("你的水月仙法太差了，不会使用五气朝元。\n");

        if( (int)me->query("gin") < (int)me->query("eff_gin") / 12 
         || (int)me->query("kee") < (int)me->query("eff_kee") / 12 
         || (int)me->query("sen") < (int)me->query("eff_sen") / 12 
        )
                return 
                        notify_fail("你已经受伤过重，只怕一运内力便有生命危险！\n");

    if(target==me){
        write( HIW "你使用五气朝元，运功疗伤。\n" NOR);
        message("vision",
                HIC + me->name() + 
                                "使用五气朝元，脸色和精神都好多了。\n" NOR,
                environment(me), ({ me }));
    }else{
        message_vision( HIW "$N使用五气朝元，为$n运功运功疗伤，$n的脸色看起来好多了。\n" NOR, me, target);
    }

        target->receive_curing("gin", amount + ((int)me->query_skill("magic") * amount /120) );
        target->set("gin", (target->query("gin")*2+target->query("eff_gin"))/3 );
        target->receive_curing("kee", amount + ((int)me->query_skill("force") * amount /120) );
        target->set("kee", (target->query("kee")*2+target->query("eff_kee"))/3 );
        target->receive_curing("sen", amount + ((int)me->query_skill("spells") * amount /120) );
        target->set("sen", (target->query("sen")*2+target->query("eff_sen"))/3 );

        me->add("atman", -amount);
        me->add("force", -amount);
        me->add("mana", -amount);
        me->start_busy(1);

        return 1;
}
