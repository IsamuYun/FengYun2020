//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(CYN "青色小刀" NOR, ({ "dao" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把很小的刀，略带一丝青色。\n");
		set("material", "steel");
		set("wield_msg", "青光一现，$N突然拔出$n！\n");
		set("unwield_msg", "$N的$n已入鞘。\n");
	}
	init_blade(80);
	setup();
}
