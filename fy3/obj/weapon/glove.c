//  An example non-weapon type of weapon

#include <weapon.h>
inherit RING;
void create()
{
	set_name("板指", ({ "ring" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个大理石的板指\n");
		set("value", 50);
		set("material", "steel");
	}
	init_ring(4);

	set("wield_msg", "$N从怀中摸出一个$n带在手指上。\n");
	set("unwield_msg", "$N将手指上的$n拿下来藏入怀中。\n");

// The setup() is required.

	setup();
}
