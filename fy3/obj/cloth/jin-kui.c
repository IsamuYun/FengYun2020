// jin-kui.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( HIY "�Ͻ��" NOR , ({ "jin kui", "hat" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "����һ���Ͻ����\n");
                set("unit", "��");
                set("value", 20000);
		set("material", "gold");
		set("armor_type", "head");
		set("armor_prop/armor", 10 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N��$nȡ������ͷ�ϡ�\n");
        }
        setup();
}
