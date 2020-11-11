#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("新疆地毯", ({ "thick carpet"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块相当厚实的新疆地毯。");		
		set("material", "cloth");
                set("value", 100);
		set("armor_prop/armor", 10);
	}
	setup();
}
