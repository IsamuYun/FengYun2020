// boots.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIR "õ�廨" NOR, ({ "rose" }) );
        set_weight( 400 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ��õ�廨��\n");
                set("unit", "˫");
                set("value", 100);
		set("material", "flower");
		set("armor_type", "head");
		set("armor_prop/armor", 2 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 2 );
        }
        setup();
}
