// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("�񱳵�", ({ "blade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_get",1);
                set("no_drop",1);
                set("value", 500);
                set("material", "iron");
                set("long", "����һ�񱳴󵶣�������Լ�����߽��ء�\n");
                set("wield_msg", "$N���һ�����λε�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }
        init_blade(75);
        setup();
}

