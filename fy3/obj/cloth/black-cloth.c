// black-cloth.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( BLK "ҹ�з�" NOR, ({ "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ����ͨ��ҹ�з���\n");
                set("unit", "��");
                set("value", 50);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        }
        setup();
}
