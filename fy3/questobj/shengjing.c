#include <ansi.h>
#include <armor.h>

inherit ITEM;

void create()
{
	set_name(CYN "圣经" NOR, ({ "shengjing"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一本用奇怪文字写的圣经。\n");
		set("unit", "本");
		
		
	}
	setup();
}

