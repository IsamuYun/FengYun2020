#include <weapon.h>
inherit DAGGER;
void create()
{
	set_name("英吉沙小刀", ({ "small blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一个很锋利的小刀，刀柄特别的漂亮。\n");
		set("material", "iron");
		set("value", 500);
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
	}
	init_dagger(20);
	setup();
}
