// wududan.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;

        if((int)me->query_skill("wudutoxin") < 20 )
                return notify_fail("你的唐门毒术不够高！\n");

        if( sheet->name() != "青蛇蜕皮" )
                return notify_fail("这种物品无法炼制出青蛇丹！\n");

     //   if( (int)me->query("mana") < 50 ) 

        //      return notify_fail("你的法力不够了！\n");

        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/dan1");
        newsheet->set_name(HIG "青蛇丹" NOR, 
                ({ "qingshedan", "dan"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "apply_medicine":));
        newsheet->move(me);
       // me->add("mana", -50);
        me->receive_damage("sen", 50);
        me->save();
        message_vision("$N炼制了一丸丹药。\n" NOR, me);
        return 1;
}