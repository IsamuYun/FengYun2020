// ken 1999.12.14

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIC"齐眉棍"NOR, ({ "staff" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这只是一根看起相当普通的齐眉棍。不知铜驼为何如此爱惜。");
                set("material", "wood");
        }
        init_staff(10);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N把$n紧紧地握在手中。\n");
        set("unwield_msg", "$N松开了手中的$n。\n");

// The setup() is required.

        setup();
}
