#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name(HIW "ę́" NOR, ({ "maotai" }) );
        set_weight(10);
        if( clonep() )
             set_default_object(__FILE__);
        else {
        set("long", "һ��ę́��\n");
                set("unit", "ƿ");
                set("value", 0);
                set("max_liquid", 20);
        }
        set("liquid", ([
                "type": "alcohol",
                "name": "ę́��",
                "remaining": 20,
                "drunk_apply": 5,
        ]) );
}
