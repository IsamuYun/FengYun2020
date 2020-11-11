inherit ITEM;
#include <ansi.h>
void create()
{
    set_name("算盘"NOR, ({ "suanpan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "把");
                set("no_get",1);
                set("no_drop",1);
           set("material", "gold");
            set("long", "一把纯金打造算盘。\n");
                set("value", 1);
        }
        setup();
}
