// stone-hiw.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "银色神石" NOR, ({ "silver stone", "stone" }) );
	set_weight( 10000 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块银色的神石，里面含有一些稀有的物质。\n");
		set("value", 100);
    };
}

