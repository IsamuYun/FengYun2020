#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(HIR "修罗刀" NOR, ({ "xiuluodao" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是秦红棉送给段正淳的定情信物。\n");
		set("material", "steel");
		set("wield_msg", "红光一闪，$N已将$n握在手中！\n");
		set("unwield_msg", "$N将$n插入刀鞘。\n");
	}
	init_blade(20);
	setup();
}
