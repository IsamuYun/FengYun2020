// feng-hat.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "���" , ({ "feng guan", "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ����ͨ�ķ�ڡ�\n");
                set("unit", "��");
                set("value", 5000);
		set("material", "gold");
		set("armor_type", "head");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N��$nȡ������ͷ�ϡ�\n");
        }
        setup();
}
