#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name( HIW"钩魂令"NOR , ({ "lin" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把阴森森的钩魂令\n");
                set("no_get",1);
                set("no_drop",1);
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放下。\n");
        }
        init_dagger(65);
        setup();
}

