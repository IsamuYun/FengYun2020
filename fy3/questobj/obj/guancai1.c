#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("丑陋的" + HIW "水晶" NOR + "棺材" , ({ "foolguancai"}) );
        set_weight(100);
	set("unit", "口");
	set("long", "一口难看的水晶棺材，除了材料，没有一点可取之处。\n");
	set("closed", 1);
	set("value", 5000);
}

