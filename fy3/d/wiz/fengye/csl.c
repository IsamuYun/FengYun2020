#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"¥Ã…±¡Ó" NOR, ({ "csl" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "øÈ");
            set("material", "stone");
}
       setup();
}
