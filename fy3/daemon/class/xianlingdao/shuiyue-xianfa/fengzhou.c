// yiru@hero

inherit SSERVER;
#include <ansi.h>
#include <condition.h>


int cast(object me)
{
        int howlong;
        
        if((int)me->query_skill("spells") < 150)
                return notify_fail("你还没学会风咒。。。\n");

        if( (int)me->query("mana") < 2*(int)me->query_skill("spells"))
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神无法集中！\n");

        message_vision("$N喃喃地念了几句咒语。\n", me);

        if( random(me->query("max_mana")) < 200 ) {
                me->add("mana",-(int)me->query_skill("spells"));
                me->receive_damage("sen",10);
                message("vision", "但是什么也没有发生。\n", environment(me));
                return 5+random(5);
        }

        me->add("mana", -2*(int)me->query_skill("spells"));
        me->receive_damage("sen", 20);

        howlong = 15 + random((me->query_skill("spells") -100));

    if(me->query_temp("apply/nature_attrib") & NA_FENG) howlong *= 2; 

        if (!me->query("env/invisibility"))
                call_out("free", howlong, me, howlong);
        me->set_temp("yinshentime", howlong+(int)me->query_temp("yinshentime"));

        me->set("env/invisibility", 1);
    me->improve_skill("shuiyue-xianfa", 1, 1);
        message_vision(HIC"\n只见$N向地上吸了一口气，再喷出来，顿时狂风大作，飞砂走石，而$N也隐身其中。\n\n"NOR, me);
        
        return 5+random(5);
}

void free(object user, int howlong)
{
        if(!user) return;
        if (!user->query("env/invisibility")) return;
        if (user->query_temp("yinshentime") - howlong) {
                user->set_temp("yinshentime", 
                        user->query_temp("yinshentime") - howlong);
                call_out("free", user->query_temp("yinshentime"), 
                        user, user->query_temp("yinshentime"));
                return;
                }
        user->delete_temp("yinshentime");
        user->delete("env/invisibility");
        user->save();
        message_vision(HIW"\n狂风过后，$N又现出了身形。\n\n"NOR, user);
        return;
}
