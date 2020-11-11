// wuyoucha.c

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(YEL"风云无忧" NOR, ({ "wuyou" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG"这是风云茶王送给大家的礼物\n" NOR);
                set("unit", "壶");
                set("max_liquid", 50);
        }


        set("liquid", ([
                "name": YEL"无忧茶" NOR,
                "remaining": 50,
        ]) );
}
