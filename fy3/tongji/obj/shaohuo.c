//  An example non-weapon type of weapon

#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("�ջ��", ({ "shaohuo" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ؽ��ڵ��ջ��\n");
                set("value", 0);
                set("material", "steel");
                set("no_get",1);
                set("no_drop",1);

        }
        init_staff(30);

        set("wield_msg", "$N��$n�������������С�\n");
        set("unwield_msg", "$N�ɿ������е�$n��\n");

// The setup() is required.

        setup();
}
