#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("完美无缺的" + HIW "水晶" NOR + "棺材" , ({ "goodguancai"}) );
        set_weight(100);
        set("unit", "口");
        set("long", "一口做工精细的水晶棺材，棺材中充满了檀香味道。\n");
        set("closed", 1);
        set("value", 5000);
}