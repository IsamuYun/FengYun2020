// silver-zhanjia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIW "����ս��" NOR, ({ "yinsuo zhanjia", "zhanjia" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����һ������ս�ס�\n");
                set("unit", "��");
                set("value", 15000);
		set("material", "silver");
		set("armor_type", "cloth");
		set("armor_prop/armor", 20 );
		// set("armor_prop/defense", 10 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
