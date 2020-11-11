// yiru@hero

#include <ansi.h>
#include <condition.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
    string msg;
    int success, ap, dp, howlong;

    if( !target ) target = offensive_target(me);

    if((int)me->query_skill("spells") < 90)
        return notify_fail("你还没学会水咒。。。\n");

    if( !target
     || !target->is_character()
     || target->is_corpse()
     || target==me)
        return notify_fail("你想对谁施水咒？\n");

    if(target->query_temp("no_move"))
        return notify_fail(target->query("name")+"已经动弹不得了！\n");

    if((int)me->query("mana") < 600 )
        return notify_fail("你的法力不够！\n");

    if((int)me->query("sen") < 10 )
        return notify_fail("你无法集中精力！\n");

    me->add("mana", -600);
    me->receive_damage("sen", 10);

    msg = HIB "$N口中念了句咒文，地面涌出滔滔洪水，将$n陷在水中！\n" NOR;

    success = 1;
    ap = me->query_skill("spells");
    ap = ap * ap * ap /10 ;
    ap += (int)me->query("combat_exp");
    dp = target->query("combat_exp");
    if( random(ap + dp) < dp ) success = 0;

    // here we compared exp and spells level. 
    // note: has nothing to do with target's spells level.

    ap = (int)me->query("max_mana");
    dp = (int)target->query("max_mana");
        if( random(ap + dp) < dp ) success = 1;

    //here we compared max_mana.

    ap = (int)me->query("mana");
    dp = (int)target->query("mana");
        if( ap < random(dp) ) success = 0;
    // here we compare current mana. this is important. you need recover to try again.

    howlong = 0;        
    if(success == 1 ){
    
        
        howlong = me->query_skill("spells") - target->query_skill("spells");
        if(me->query_temp("apply/nature_attrib") & NA_SHUI) 
            howlong += me->query_skill("spells");
        
        if(howlong >0 && howlong<6) howlong = 6;
        if(howlong <0 && howlong>-3) howlong = -3;
        
        if(howlong <0){
            msg +=  HIB "结果$N自己被水淹了！\n" NOR;
            me->set_temp("no_move", 1);
            me->improve_skill("shuiyue-xianfa", 1, 1);
        }else if(howlong>0){
            msg +=  HIB "结果$n"HIB"在水中挣扎，已顾不上战斗了！\n" NOR;
            target->set_temp("no_move", 1);
            me->improve_skill("shuiyue-xianfa", 1, 1);
        }else msg +=  "结果什么都没有发生。\n";

        // a typical level is 100+100 ->enabled 150, 
        // so will "ding" about 1 minute in the best case.
    } else {
        msg +=  HIC "结果$n微微一笑，一口气吹去，滔滔洪水瞬时退去！\n" NOR; 
    } 

    message_vision(msg, me, target);

    if (success == 0) {
        me->start_busy(3);
        // he'll try kill you...
        if( living(target) ) target->fight_ob(me);
        return 1;
    }
    
    me->start_busy(1);

    if( howlong>0 ) call_out("free", howlong, target);
    else if( howlong<0 ) call_out("free", -howlong, me);
        
    return 1;
}

void free(object target)
{
    if(target) target->delete_temp("no_move");
    tell_object(target, "水咒还原了。\n");
    return;
}
