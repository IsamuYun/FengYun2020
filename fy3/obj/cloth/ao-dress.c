// ao-dress.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "ȹ��", ({ "ao dress", "dress", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ����ͨ��ȹ����\n");
                set("unit", "��");
                set("value", 500);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 1 );
        }
        setup();
}
