// tong-kui.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( YEL "ͭ��" NOR , ({ "tong kui", "hat" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ����ͨ��ͭ����\n");
                set("unit", "��");
                set("value", 8000);
		set("material", "corpper");
		set("armor_type", "head");
		set("armor_prop/armor", 7 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N��$nȡ������ͷ�ϡ�\n");
        }
        setup();
}
