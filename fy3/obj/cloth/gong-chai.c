// gong-chai.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( WHT "����" NOR , ({ "gong chai", "chai" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ֧��ͨ�Ĺ��Ρ�\n");
                set("unit", "֧");
                set("value", 6000);
		set("material", "gold");
		set("armor_type", "head");
		set("armor_prop/armor", 3 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N��$n�ó�����ͷ���ϡ�\n");
        }
        setup();
}
