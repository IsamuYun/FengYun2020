// xueblade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(RED"滴血刀"NOR, ({ "xueblade" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1000);
		set("material", "iron");
		set("long", "这是一把充满邪气和杀机的钢刀。\n");
		set("wield_msg", " $N抽出一把殷红$n握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	init_blade(50);
	setup();
}
