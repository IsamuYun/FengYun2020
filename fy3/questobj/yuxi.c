#include <ansi.h>
#include <armor.h>

inherit ITEM;

void create()
{
	set_name(HIY "大理玉玺" NOR, ({ "yuxi"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "大理国的传国玉玺。\n");
		set("unit", "块");
		
		
	}
	setup();
}

