#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
        object *ob;
        int i, skill, damage;

        if( (int)me->query("force") < 150 )
                return notify_fail("你的内力不够。\n");
        if( environment(me)->query("no_fight") )
                return notify_fail("这里不准使用。\n");

        skill = me->query_skill("force");

        me->add("force", -150);
        me->receive_damage("kee", 10);

        me->start_busy(3);
        message_vision(
                HIY "$N神功妙悟，突然间望月长啸，其声绵绵不绝！\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;
                
                damage = skill - ((int)ob[i]->query("max_force") / 10);
                if( damage > 0 && ob[i]->query("combat_exp")>1000000) {
                        ob[i]->receive_damage("sen", damage);
                        if( (int)ob[i]->query("force") < skill * 2 )
                                ob[i]->receive_wound("sen", damage);
        message_vision("$N被啸声一震，只觉得头晕眼花，心神涣散。\n",ob[i]);
                }
                ob[i]->kill_ob(me);
        }

        return 1;
}
