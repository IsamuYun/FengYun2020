// cao-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("��Ь", ({ "cao xie", "boots" }) );
        set_weight( 300 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ˫��ͨ�Ĳ�Ь��\n");
                set("unit", "˫");
                set("value", 50);
		set("material", "grass");
		set("armor_type", "boots");
		set("armor_prop/armor", 0 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 1 );
        }
        setup();
}
