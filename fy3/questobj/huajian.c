// ken 1999.12.7

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIB"种花剪"NOR, ({ "huajian" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("jungle",1);
		set("material", "iron");
		set("long", "这是一个花剪\n");
		set("wield_msg", "$N拿出一个种花用的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n放回怀里。\n");
	}
	init_blade(5);
	setup();
}
