// corpper-zhanjia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( YEL "ͭ��ս��" NOR, ({ "tongsuo zhanjia", "zhanjia" }) );
        set_weight(25000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����һ��ͭ��ս�ס�\n");
                set("unit", "��");
                set("value", 10000);
		set("material", "corpper");
		set("armor_type", "cloth");
		set("armor_prop/armor", 10 );
		// set("armor_prop/defense", 5 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
