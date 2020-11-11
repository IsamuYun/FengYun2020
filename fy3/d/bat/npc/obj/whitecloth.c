// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("雪白绸衫", ({ "White silk cloth","white silk cloth"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是风云城时下最时髦的衣服。\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
