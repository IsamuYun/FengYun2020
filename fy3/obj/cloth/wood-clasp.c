// wood-clasp.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( YEL "ľ��" NOR , ({ "wood clasp", "clasp" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ֧��ͨ��ľ����\n");
                set("unit", "֧");
                set("value", 50);
		set("material", "wood");
		set("armor_type", "head");
		set("armor_prop/armor", 0 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N��$n�ó�����ͷ���ϡ�\n");
        }
        setup();
}
