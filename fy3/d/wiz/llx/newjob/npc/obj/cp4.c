#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"大昭茶票" NOR, ({ "chapiao" }));
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张给大昭寺附近农民的茶票。\n");
          }

    setup();
}
