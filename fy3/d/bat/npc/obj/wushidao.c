#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIR"映日武士刀"NOR, ({ "wushidao" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 400000);
		set("material", "steel");
		set("long", "这是一把似剑的东瀛武士刀。\n");
		set("wield_msg", "$N从刀鞘中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
        init_blade(140);
	setup();
}
