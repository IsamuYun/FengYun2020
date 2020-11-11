// xiesword.c : master xie's weapon
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIW "如雪"NOR, ({ "snowsword" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把宝剑，上铸‘如雪’二字。\n");
		set("value", 4000);
		set("material", "steel");
	}
	init_sword(105);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

// The setup() is required.

	setup();
}
