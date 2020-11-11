// yiru@hero
// huanhun.c
// 还魂咒

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert_to_me(object me, object target,int amount)
{
    me->add("atman", -amount );
    me->add("mana", -amount );
    if (random(me->query_skill("shuiyue-xianfa",1)) < 30)
    {           
        write("你失败了。\n");
        me->start_busy(1);
        return 1;
    } else {
        if(me!=target)
            message_vision("$N将一股内力输入到$n体内，$n看起来精神好多了。\n", me, target);
        else
            message_vision("$N深吸了一口气，看起来精神好多了。\n", me);
        target->set("gin",(target->query("gin")+target->query("eff_gin"))/2);
        target->set("sen",(target->query("sen")+target->query("eff_sen"))/2);
        me->start_busy(1);
        return 1;
    }
}

int exert(object me, object target, int amount)
{
    int lvl;

    if(amount<60) amount=60;

    if(me->query_skill("shuiyue-xianfa",1)<120)
        return notify_fail("你的水月仙法太差了！\n");

    if( (int) me->query("force") < amount) 
        return notify_fail("你的内力不足。\n");
    if( (int) me->query("atman") < amount) 
        return notify_fail("你的灵力不足。\n");
    if( (int) me->query("mana") < amount) 
        return notify_fail("你的法力不足。\n");

    if( !target ) {
        exert_to_me(me,target,amount);
        return 1;
    }

    if(!target->query_temp("is_unconcious")){
        exert_to_me(me,target,amount);
        return 1;
    }

    lvl = me->query_skill("shuiyue-xianfa",1);

    me->add("force", -amount );
    if (random(lvl+amount/3) < 60)
    {           
        me->start_busy(3);
        write("你失败了。\n");
    } else {
        me->add("force", amount/3 );
        message_vision("$N将一股内力输入到$n体内。。。\n", me, target);
        target->revive();
        write("你成功了！\n");
    }
    if(me->query("force")<60){
        message_vision("$N真气消耗过度，晕了过去。",me);
        me->unconcious();
    }
    return 1;
}
