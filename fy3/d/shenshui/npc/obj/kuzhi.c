//copy to /d/shenshui/npc/obj/kuzhi.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("枯树枝", ({ "kuzhi" }) );
	set_weight(4000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("unit", "段");
		set("material", "wood");
		set("long", "枯枝很普通，但是它的切口看起来是用剑削出的．\n");
	}
	init_blade(5);
	setup();
}
