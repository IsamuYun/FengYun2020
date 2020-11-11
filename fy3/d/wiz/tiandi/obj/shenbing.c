#include <ansi.h>
#include <weapon.h>
inherit	RING;
void create()
{
	set_name( HIY "新手拳套" NOR, ({ "ring" })	);
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "新手套装之一，新手拳套是新手必备的东西，可以有效地帮助新手成长。\n\n");
                set("material", "steel");
	  set("no_get",1);
       				set("limited_lv",1);
              set("abradability",500);
	}
	init_ring(50);
	setup();
}


int query_autoload() { return 1; }


