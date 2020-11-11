// diamond-earth.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "土晶石" NOR, ({ "earth diamond", "diamond" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
    		set("long", @LONG 
这是一颗土晶石。
LONG
  		);
		set("value", 200000);
		set("material", "diamond");
    	};
        setup();
}
