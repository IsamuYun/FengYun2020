//欢乐英雄
//function for water beast
//by lion@hero

#include <ansi.h>

int update_condition(object me, int duration)
{
    object beast;
    me->apply_condition("water_beast", duration - 1);
    if( duration < 1 ){ 
    beast = new("/d/heimiao/npc/waterbeast");
    message_vision(HIG"水魔兽"HIR"又复活了！摇摆着臃肿的身躯向$N游了过来！\n"NOR,me);
    beast->move(environment(me));
    return 0;
     }
    if(!me->query_temp("water_beast")){   //使用临时变量，处理玩家突然离线的情况。
    me->apply_condition("water_beast", 0);
    return 0;  
     }
    return 1;
}
string query_type() { return "waterbeast"; }
