#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( HIW "水晶" NOR, ({ "shuijing" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是大块晶莹的水晶，听说利用它作成的棺材可以保证尸体很长时间不腐烂。\n");
		set("value", 40000);
		set("material", "stone");
		set("rigidity", 20000);
	}
	setup();
}
