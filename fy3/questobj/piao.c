// ken 1999.12.7

#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIW"貂皮袄"NOR, ({ "piao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件貂皮袄，在冰天雪地里穿着，真是再好不过了。\n");
		set("material", "cloth");
		set("armor_prop/intelligence",3);
	}
	setup();
}
