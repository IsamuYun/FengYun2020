// diamond-gold.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "金晶石" NOR, ({ "gold diamond", "diamond" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
    		set("long", @LONG 
这是一颗金晶石。
LONG
  		);
		set("value", 200000);
		set("material", "diamond");
    	};
        setup();
}
