// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("装满的酒葫芦", ({ "fullhulu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("value", 10000);
            set("material", "paper");
            set("long", "一个装满各种风味美酒的酒葫芦。\n");
          }

    setup();
}

