// stick.c ����

#include <weapon.h>

inherit STICK;

void create()
{
        set_name("����", ({ "stick" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ��������\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg", "$N��ৡ���һ���γ�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_stick(25);
        setup();
}
