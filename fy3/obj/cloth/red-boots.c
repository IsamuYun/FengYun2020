// red-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( HIR "��״��Ь" NOR, ({ "red boots", "boots" }) );
        set_weight( 1000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ˫�����ɫ�ĺ��Ь�ӡ�\n");
                set("unit", "˫");
                set("value", 1000);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 3 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
