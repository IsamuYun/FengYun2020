// tou-kui.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "ͷ��" , ({ "tou kui", "hat" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ����ͨ��ͷ����\n");
                set("unit", "��");
                set("value", 1000);
		set("material", "bamboo");
		set("armor_type", "head");
		set("armor_prop/armor", 5 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N��$nȡ������ͷ�ϡ�\n");
        }
        setup();
}
