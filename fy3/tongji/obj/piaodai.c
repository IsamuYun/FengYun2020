#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{       string piaod;
        set_name( "���Ʈ��" NOR, ({ "piaodai" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
               set("value", 500000);
                set("material", "skin");
                set("rigidity", 100);
        }
        init_whip(55);
                set("no_get",1);
                set("no_drop",1);

        set("wield_msg", "$N����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        setup();
}

