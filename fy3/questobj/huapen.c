#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(MAG"景致花盆" NOR, ({ "huapen" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
            set("long", "一个华赫艮栽花用的花盆。\n");
}
    setup();
}
