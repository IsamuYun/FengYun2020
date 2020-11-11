// ling.c
#include <weapon.h>

inherit LING;

void create()
{
	set_name("铜铃", ({ "ling" }));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("value", 500);
		set("material", "corpper");
		set("long", "这是一只寻常的铜铃。\n");
		set("wield_msg", "$N抽出一只明晃晃的$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放回腰间。\n");
	}
	init_ling(20);
	setup();
}
