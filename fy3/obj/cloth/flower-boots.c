// flower-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("�廨Ь", ({ "flower boots", "boots" }) );
        set_weight( 500 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ˫��ͨ���廨Ь��\n");
                set("unit", "˫");
                set("value", 2500);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 3 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
