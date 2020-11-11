// gold-dan.c - 九转金丹

#include <ansi.h>

inherit PILL;

void create()
{
        set_name( HIY "九转金丹" NOR, ({ "gold dan", "dan" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是可以内服（use）的$HIY$九转金丹$NOR$，它们是只有神仙才拥有的东西。
TEXT
                );
                
                set("unit", "些");
                set("base_unit", "粒");
                set("base_weight", 10);
                set("value", 0 );
        }

        set_amount(1);

        setup();
}

void get_effect( object who ) 
{
        int increasement;

        increasement = 3000 + random( 2000 );
        who->add("potential", increasement);
        tell_object(who, "你的潜能增加了" + chinese_number( increasement ) + "点！\n");
}
