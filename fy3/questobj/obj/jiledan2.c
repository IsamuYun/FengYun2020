#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("极乐丹粉", ({ "danfen" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "些");
            set("material", "stone");
            set("value", 10000);
            set("long", "一些补足了药力的极乐丹粉。\n");
          }

    setup();
}

