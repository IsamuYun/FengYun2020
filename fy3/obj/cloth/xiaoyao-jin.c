// xiaoyao-jin.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "��ң��" , ({ "xiaoyao jin", "hat" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ����ͨ����ң��\n");
                set("unit", "��");
                set("value", 100);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 0 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N��$nȡ������ͷ�ϡ�\n");
        }
        setup();
}
