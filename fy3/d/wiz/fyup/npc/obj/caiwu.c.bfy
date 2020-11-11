// level sheet.c by tiandi

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW  "冶炼符" NOR, ({ "level sheet" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "一张符咒，似乎可以提升某种神秘的力量。\n");
		set("value", 100000);
	
	}
	setup();
}
