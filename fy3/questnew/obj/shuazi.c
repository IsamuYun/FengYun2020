#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("毛刷", ({ "shuazi" }) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("material", "wood");
                set("long", "这是一把毛刷。\n");
        }
        setup();
}