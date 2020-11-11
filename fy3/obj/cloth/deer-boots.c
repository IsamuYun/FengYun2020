// deer-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("Â¹Æ¤Ð¡Ñ¥", ({ "deer boots", "boots" }) );
        set_weight( 1000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "Ò»Ë«Â¹Æ¤×öµÄÑ¥×Ó¡£\n");
                set("unit", "Ë«");
                set("value", 2000);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 4 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 1 );
        }
        setup();
}
