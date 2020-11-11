// wood-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("Ä¾åì", ({ "mu ji", "boots" }) );
        set_weight( 500 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "Ò»Ë«Ä¾Í·×öµÄÄ¾åì¡£\n");
                set("unit", "Ë«");
                set("value", 100);
		set("material", "wood");
		set("armor_type", "boots");
		set("armor_prop/armor", 2 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
