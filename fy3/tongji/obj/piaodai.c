#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{       string piaod;
        set_name( "五彩飘带" NOR, ({ "piaodai" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
               set("value", 500000);
                set("material", "skin");
                set("rigidity", 100);
        }
        init_whip(55);
                set("no_get",1);
                set("no_drop",1);

        set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");
        setup();
}

