#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("完整的" +HIY"金算盘"NOR, ({ "suanpans" }) );
    set_weight(30000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "把");
            set("value",40000);
            set("material", "gold");
            set("long", "一把纯金打造的算盘\n");
          }

    setup();
}
