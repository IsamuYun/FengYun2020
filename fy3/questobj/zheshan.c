#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIW"折扇"NOR, ({ "zheshan" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("jungle",1);
		set("material", "wood");
		set("long", "这是一把精致的折扇。\n");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间。\n");
	}
	init_blade(5);
	setup();
}
