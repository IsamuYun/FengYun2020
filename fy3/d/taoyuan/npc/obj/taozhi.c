
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("桃枝" , ({ "taozhi", "桃枝" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枝");
		set("long", "桃枝上开满了粉红色的花朵!\n");
		set("value", 5);
		set("rigidity", 5);
		set("material", "wood");
		set("wield_msg", "$N拿出一枝开满了粉红色花朵的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(5);
	setup();
}
