// xiaozhan-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("���Сսѥ", ({ "xiao zhanxue", "boots" }) );
        set_weight( 1000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ˫�����ɫ��Сսѥ��\n");
                set("unit", "˫");
                set("value", 6000);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 8 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 2 );
        }
        setup();
}
