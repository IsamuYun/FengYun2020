// silver-chai.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( HIW "����" NOR , ({ "silver chai", "chai" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ֧��ͨ�����Ρ�\n");
                set("unit", "֧");
                set("value", 500);
		set("material", "silver");
		set("armor_type", "head");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N��$n�ó�����ͷ���ϡ�\n");
        }
        setup();
}
