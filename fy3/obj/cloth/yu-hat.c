// yu-hat.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( WHT "�����" NOR , ({ "biyu guan", "hat" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����һ���ı���ڡ�\n");
                set("unit", "��");
                set("value", 10000);
		set("material", "gold");
		set("armor_type", "head");
		set("armor_prop/armor", 5 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N��$nȡ������ͷ�ϡ�\n");
        }
        setup();
}
