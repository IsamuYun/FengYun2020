// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("·çÔÆÕ½¼×", ({ "zhanjia" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("material", "steel");
                set("value", 8000);
		set("armor_prop/armor", 10);
		set("limited_lv",1);
		set("abradability",100);
	}
	setup();
}
