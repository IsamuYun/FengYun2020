//  An example non-weapon type of weapon
#include <ansi.h>
#include <weapon.h>
inherit RING;
void create()
{
        set_name(HIW"����"NOR, ({ "tiegou" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������������ƺ��ܷ�����\n");
                set("value", 0);
                set("material", "steel");
                set("no_get",1);
                set("no_drop",1);

        }
        init_ring(50);

        set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
        set("unwield_msg", "$N�����ϵ�$n���뻳�С�\n");

// The setup() is required.

        setup();
}
