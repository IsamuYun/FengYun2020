// fork.c �ֲ�

#include <weapon.h>

inherit FORK;

void create()
{
        set_name("�ֲ�", ({ "fork" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "����һ֧��ͨ�ĸֲ档\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ���γ�һ֧$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
				set("limited_lv",1);
        }
        init_fork(25);
        setup();
}