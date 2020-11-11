// xiaochao-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("·Ûµ×Ð¡³¯Ñ¥", ({ "xiao chaoxue", "boots" }) );
        set_weight( 1000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "Ò»Ë«·Ûµ×Ð¡³¯Ñ¥¡£\n");
                set("unit", "Ë«");
                set("value", 12000);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 3 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 2 );
        }
        setup();
}
