#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( HIB "太极八卦道袍" NOR, ({ "daopao" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一件画有太极八卦的袍\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
