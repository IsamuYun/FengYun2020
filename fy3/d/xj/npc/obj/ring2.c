#include <armor.h>

inherit FINGER;

void create()
{
	set_name("结婚戒指", ({ "wedding ring", "ring"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 1000000);
		set("wear_msg", "$N轻轻地把一个$n戴在手指上。\n");
		set("unwield_msg", "$N轻轻地把$n从手指上除了下来。\n");
	}
	setup();
}