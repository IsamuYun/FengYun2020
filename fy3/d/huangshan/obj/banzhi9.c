// TIE@FY3
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
        set_name(HIR  "鸡血神石" NOR, ({ "old iron" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
                set("long", "传说是仙人留下的东西，外观红如血，却硬比金刚石。\n");

		set("value", 50000);
		set("rigidity",2000);	
		set("material", "steel");
		set("max_enchant",6);
                set("for_create_weapon",9);
	}
	init_dagger(20);
	set("wield_msg", "$N从怀中摸出一块$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n藏入怀中。\n");
	setup();
}
