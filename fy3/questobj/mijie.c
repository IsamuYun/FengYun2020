#include <ansi.h>
inherit ITEM;
inherit F_FOOD;


void create()
{
        set_name(HIC "公平蜜饯" NOR, ({ "mijie"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是公平子常吃的蜜饯\n");
                set("unit", "个");
                set("food_remaining", 3);
                set("food_supply", 20);
                set("value", 500);
                set("eat_msg", "$N把一颗$n丢进了嘴里。\n");
                set("tu_msg", "$N把$n的核吐了出来。\n");
     }
       setup();
}
 
