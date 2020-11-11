// diamond-wood.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "木晶石" NOR, ({ "wood diamond", "diamond" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
    		set("long", @LONG 
这是一颗木晶石。
LONG
  		);
		set("value", 200000);
		set("material", "diamond");
    	};
        setup();
}
