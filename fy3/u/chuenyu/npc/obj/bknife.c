// knife.c

#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("����", ({ "knife" }) );
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѵ����ż�����������ʱ���ϴ͵ı���");
                set("value", 20000);
                set("material", "crimsonsteel");
        }
        init_dagger(15);

        set("wield_msg", "$N��������һ����������$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");


        setup();
}

