#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
 object obj;

 if (!arg) return notify_fail("你要拔什么?\n");
 if( !objectp(obj = present(arg, me)) )
        return notify_fail("你身上没有这样东西。\n");
 if (!obj->query("prick") && obj->query("prick")!=me)
        return notify_fail("这样东西没有插在你身上！\n");
 if(me->is_busy())
        return notify_fail("你上一个动作还没有完成！\n");

 
message_vision(HIR "$N握住$n咬牙狠心一拔！\n" NOR, me, obj);
obj->move(environment(me));
message_vision(HIR "$N大叫一声将$n拔了出来，一股血箭喷了出来！\n" NOR, me, obj);
me->receive_wound("kee", 200);
me->receive_wound("sen", 200);
me->apply_condition("throw_poison", 0);

obj->delete("prick");
obj->delete_temp("prick");
obj->delete_temp("pricked");
obj->set("name",(string)me->query_temp("prick"));
me->delete_temp("prick");
return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : drag_out <物品名称> 
当你被箭一类兵器所伤之后,该兵器会留在你的体内,所以,你需要拔除他们.
这个指令是将此类的兵器从体内拔除.但是拔除时会给你的身体带来伤害.
如果让他们留在你的体内,一方面会增加负重,另一方面,当它们越来越多时,
一次拔除可能会由于受伤过重使你丧命.
HELP
    );
    return 1;
}

