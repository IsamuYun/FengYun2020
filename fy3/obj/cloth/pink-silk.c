// pink-silk.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIM "�ۺ����" NOR, ({ "pink dress", "dress", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ����ͨ�ķۺ������\n");
                set("unit", "��");
                set("value", 1000);
		set("material", "silk");
		set("armor_type", "cloth");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 3 );
        }
        setup();
}
