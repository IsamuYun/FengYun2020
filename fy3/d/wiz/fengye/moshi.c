#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"磨石" NOR, ({ "moshi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "块");
            set("material", "stone");
            set("long", "一块磨剑的石头。\n");
}
    setup();
}
