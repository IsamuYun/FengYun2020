// wood-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("ľ��", ({ "mu ji", "boots" }) );
        set_weight( 500 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ˫ľͷ����ľ�졣\n");
                set("unit", "˫");
                set("value", 100);
		set("material", "wood");
		set("armor_type", "boots");
		set("armor_prop/armor", 2 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
