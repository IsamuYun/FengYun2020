
#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("竹筷子", ({ "chopstick" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("long", "一对吃饭用的竹筷子。\n");
		set("value", 20);
		set("material", "wood");
		set("rigidity", 10);
		set("wield_msg", "$N拿出一对$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	init_dagger(11);
	setup();
}
