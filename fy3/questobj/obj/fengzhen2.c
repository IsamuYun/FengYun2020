// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("系上了线的花风筝" , ({ "fixfengzhen" }) );
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("value", 10000);
            set("material", "paper");
            set("long", "一个小风筝。已经系上细棉线，如果有风来，它一定会飞得很高。\n");
          }

    setup();
}

