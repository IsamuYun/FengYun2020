// gold-zhanjia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIY "����ս��" NOR, ({ "jinsuo zhanjia", "zhanjia" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����һ������ս�ס�\n");
                set("unit", "��");
                set("value", 20000);
		set("material", "gold");
		set("armor_type", "cloth");
		set("armor_prop/armor", 30 );
		// set("armor_prop/defense", 20 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
