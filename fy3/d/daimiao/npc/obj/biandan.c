#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("��ľ�ⵣ", ({ "biandian" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѿ����൱��ͨ��ľ�ⵣ");
                set("value", 300);
                set("material", "wood");
        }
        init_staff(10);
        set("wield_msg", "$N��$n�������������С�\n");
        set("unwield_msg", "$N�ɿ������е�$n��\n");
        setup();
}
