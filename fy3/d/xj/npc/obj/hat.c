#include <armor.h>
inherit HEAD;
void create()
{
	set_name("维吾尔花帽", ({ "cotton hat"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一顶很有特色，又很好看的帽子。");
		set("unit", "顶");
		set("material", "cloth");
		set("value", 100);
		set("armor_prop/armor", 1);
	}
	setup();
}
