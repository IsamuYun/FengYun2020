// wood_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("ľ��", ({ "wood sword", "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ľͷ���ɵĽ�����������Բ����������ͬ�顣\n");
                set("value", 200);
                set("material", "bamboo");
                set("wield_msg", "$N�ó�һ�������õ�$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_sword(8);
        setup();
}
 
