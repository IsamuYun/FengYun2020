// yiru@hero
// heal.c
// 观音咒

#include <ansi.h>

int exert(object me, object target, int amount)
{
                if(amount<60) amount=60;
        if( (int)me->query("force") < amount )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("sen") < amount )
                return notify_fail("你现在心神不宁，强运观音咒恐怕很危险！\n");
        if( (int)me->query_skill("shuiyue-xianfa",1) < 60 )
                return notify_fail("你的水月仙法太差了，不会使用观音咒。\n");

        if( (int)me->query("kee") < (int)me->query("eff_kee") / 10 )
                return 
                        notify_fail("你已经受伤过重，只怕一运内力便有生命危险！\n");

    if(target==me){
        write( HIW "你使用观音咒，运功敛气。\n" NOR);
        message("vision",
                HIC + me->name() + 
                                "使用观音咒敛气，顿时脑清目明达到灵神和一的境界。。。\n" NOR,
                environment(me), ({ me }));
    }else{
        message_vision( HIW "$N将观音咒施在$n身上。。。$n顿时平静了下来。\n" NOR, me, target);
    }

        target->set("kee", (target->query("eff_kee")+target->query("kee")*2)/3);
        me->add("force", -amount);
        if(me->query("bellicosity") > me->query_skill("force") ){
            me->add("bellicosity", - me->query_skill("force") );
            me->receive_damage("sen", amount);
        }

        me->start_busy(1);

        return 1;
}
