// bamboo_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("��", ({ "bamboo blade", "blade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200);
                set("material", "bamboo");
                set("long", "����һ���ñ�ƽ����Ƭ���ɵ��񵶡�\n");
                set("wield_msg", "$N�ó�һ�������õ�$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_blade(10);
        setup();
}
 
