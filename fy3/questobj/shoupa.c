inherit ITEM;
#include <ansi.h>

void create()
{
        set_name( HIC "鸳鸯手帕" NOR, ({ "shoupa" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "这是阮星竹给段正淳的定情信物。\n");
	}
	setup();
}
