// corpper-baojia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( YEL "ͭ������" NOR, ({ "tongkai baojia", "baojia" }) );
        set_weight(35000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����һ��ͭ�����ס�\n");
                set("unit", "��");
                set("value", 20000);
		set("material", "corpper");
		set("armor_type", "cloth");
		set("armor_prop/armor", 20 );
		// set("armor_prop/defense", 10 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
