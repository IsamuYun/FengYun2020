// gold-baojia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIY "��������" NOR, ({ "jinkai baojia", "baojia" }) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����һ���������ס�\n");
                set("unit", "��");
                set("value", 50000);
		set("material", "gold");
		set("armor_type", "cloth");
		set("armor_prop/armor", 50 );
		// set("armor_prop/defense", 30 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
