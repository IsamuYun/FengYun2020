#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLU"…Õ∑£¡Ó" NOR, ({ "sfl" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "øÈ");
            set("material", "stone");
            set("long", "…œ√Ê–¥◊≈:¡Ó°£\n");
}
    setup();
}
