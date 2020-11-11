// golden_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("圣剑", ({ "god sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把闪闪发光的长剑。\n");
                set("value", 10000);
        set("no_get",1);
        set("no_drop",1);
            set("weapon_prop/spirituality", 5);
                set("material", "gold");
        }
        init_sword(75);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

// The setup() is required.

        setup();
}
