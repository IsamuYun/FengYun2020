// sixhammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("�˽Ǵ�", ({ "eighthammer" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѱ˽�ͭ���������ġ�\n");
                set("value", 400);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
				set("limited_lv",1);
				set("abradability",100);
        }

        init_hammer(25);
        setup();
}