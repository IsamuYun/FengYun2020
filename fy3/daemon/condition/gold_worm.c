// three_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
    if( duration < 0 )
        return 0;
    me->receive_wound("gin", (int)me->query("max_gin")/7);
    me->receive_damage("kee", (int)me->query("max_kee")/7);
    me->receive_damage("sen", (int)me->query("max_sen")/7);

    me->apply_condition("gold_worm", duration - 1);
    if( duration < 1 )
        message_vision( HIW "$N中的" HIY "金蚕蛊" HIW "终于发作光了！\n" NOR , me);
    else
        message_vision( HIW "$N中的" HIY "金蚕蛊" HIW "发作了！\n" NOR , me);
    if(me->query_condition("bowel_grass")>0){
        message_vision( HIY "$N中的"HIG "断肠草" HIW"和" HIY"金蚕蛊"HIW "一起发作了！\n" NOR , me);
        if(!me->query_temp("is_unconcious")) me->unconcious();
    }
    me->set_temp("die_type","金蚕蛊发作而死");
    if( duration < 1 )
        return 0;
    return 1;
}

int check_condition(object me)
{
    if(me->query_condition("peafowl_gall")>0){
        me->apply_condition("peafowl_gall", -1);
        message_vision( HIW "$N中的" HIM "孔雀胆" HIW "解除了！\n" NOR , me);
        return 1;
    }
    return 0;
}
string query_type() { return "seven-poison"; }
