// golden_armor.c

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("���ս��", ({ "golden armor", "armor" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "gold");
		set("value", 9000);
                set("no_get",1);
                set("no_drop",1);

		set("armor_prop/armor", 50);
		set("armor_prop/dodge", -20);
	}
	setup();
}
