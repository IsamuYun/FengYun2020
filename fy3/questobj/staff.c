// ken 1999.12.14

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIC"��ü��"NOR, ({ "staff" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ֻ��һ�������൱��ͨ����ü������֪ͭ��Ϊ����˰�ϧ��");
                set("material", "wood");
        }
        init_staff(10);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N��$n�������������С�\n");
        set("unwield_msg", "$N�ɿ������е�$n��\n");

// The setup() is required.

        setup();
}
