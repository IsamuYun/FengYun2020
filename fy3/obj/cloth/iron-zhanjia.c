// iron-zhanjia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( WHT "����ս��" NOR, ({ "tiesuo zhanjia", "zhanjia" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����һ������ս�ס�\n");
                set("unit", "��");
                set("value", 5000);
		set("material", "iron");
		set("armor_type", "cloth");
		set("armor_prop/armor", 5 );
		// set("armor_prop/defense", 5 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
