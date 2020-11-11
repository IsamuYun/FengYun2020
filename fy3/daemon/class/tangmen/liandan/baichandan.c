// wududan.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;

        if((int)me->query_skill("wudutoxin")< 30 )
                return notify_fail("你的五毒毒术不够高！\n");

        if( sheet->name() != "白蟾角膜" )
                return notify_fail("这种物品无法炼制出白蟾丹！\n");

     //   if( (int)me->query("mana") < 50 ) 

        //      return notify_fail("你的法力不够了！\n");

        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/dan2");
        newsheet->set_name(HIW "白蟾丹" NOR, 
                ({ "baichandan", "dan"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "apply_medicine":));
        newsheet->move(me);
       // me->add("mana", -50);
        me->receive_damage("sen", 50);
        me->save();
        message_vision(HIG "$N炼制了一丸丹药。\n" NOR, me);
        return 1;
}