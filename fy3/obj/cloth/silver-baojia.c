// silver-baojia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIW "��������" NOR, ({ "yinkai baojia", "baojia" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����һ���������ס�\n");
                set("unit", "��");
                set("value", 30000);
		set("material", "silver");
		set("armor_type", "cloth");
		set("armor_prop/armor", 30 );
		// set("armor_prop/defense", 20 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
