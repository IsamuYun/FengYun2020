#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name(HIM "二锅头" NOR, ({ "egt" }) );
        set_weight(10);
        if( clonep() )
             set_default_object(__FILE__);
        else {
set("long", "一杯二锅头。\n");
                set("unit", "瓶");
                set("value", 0);
                set("max_liquid", 20);
        }
        set("liquid", ([
                "type": "alcohol",
                "name": "二锅头",
                "remaining": 20,
                "drunk_apply": 5,
        ]) );
}
