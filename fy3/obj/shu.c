// movebook.c


#include <ansi.h>
inherit ITEM;


void create()
{
	set_name("书信", ({ "shu" }));
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
                set("for_badp",1);
		set("long",
			"一封萧秋水给尉迟二的信。\n");
	set("value", 0);
		


	}
	setup();
}


