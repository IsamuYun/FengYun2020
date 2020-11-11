// TIE@FY3
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
         set_name(HIW  "盘古之石" NOR, ({ "old iron" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
         set("long", "一块由盘古开天之时遗留下来的神石。\n");
		set("value", 50000);
		set("rigidity",2000);	
		set("material", "steel");
		set("max_enchant",6);
        set("for_create_weapon",10);
	}
	init_dagger(20);
	set("wield_msg", "$N从怀中摸出一块$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n藏入怀中。\n");
	setup();
}
