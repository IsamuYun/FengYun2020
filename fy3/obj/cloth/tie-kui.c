// tie-kui.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( WHT "����" NOR , ({ "tie kui", "hat" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ����ͨ��������\n");
                set("unit", "��");
                set("value", 5000);
		set("material", "iron");
		set("armor_type", "head");
		set("armor_prop/armor", 6 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N��$nȡ������ͷ�ϡ�\n");
        }
        setup();
}
