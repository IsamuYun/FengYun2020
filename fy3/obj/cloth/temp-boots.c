// boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name(HIC "ˮ��Ь" NOR, ({ "shuijing xie", "boots" }) );
        set_weight( 400 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ˫ˮ��Ь��\n");
                set("unit", "˫");
                set("value", 100);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 2 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 2 );
        }
        setup();
}
