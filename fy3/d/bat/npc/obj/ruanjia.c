// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
void create()
{
	set_name(HIY"金丝软甲"NOR, ({ "ruanjia" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "steel");
        set("value", 1);
		set("armor_prop/armor", 200);
		set("long", "这是一件似金非金、似衣非衣的软甲，暗暗的放出
动人的金色光芒，一看就是天下奇珍。\n");


	}
	setup();
}
