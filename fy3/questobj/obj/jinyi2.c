// ken 1999.12.7

#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("修好的金镂玉衣", ({ "goodjinyi" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件金丝与玉片做成的衣衫，看上去倒象是一件盔甲。\n");
		set("material", "cloth");
                set("value", 10000);
		set("armor_prop/armor",80);		
	}
	setup();
}
