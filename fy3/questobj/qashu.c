#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"情书" NOR, ({ "qingshu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "份");
            set("material", "paper");
            set("long", "一份张军向花寡妇求爱的信。\n");
          }

    setup();
}
