#include <ansi.h>
#include <weapon.h>
inherit ITEM;
void create()
{
        set_name( "哈哈儿的人头", ({ "tou" }) );
        set_weight(1400);
                set("unit", "个");
                set("long",
                        "一个刚刚砍下来的，血淋淋的人头。\n");
                set("value", 0);
        setup();
}
