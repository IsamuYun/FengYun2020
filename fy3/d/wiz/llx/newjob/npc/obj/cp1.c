#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(YEL"沉香茶票" NOR, ({ "chapiao" }));
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张给沉香镇农民的茶票。\n");
          }

    setup();
}
