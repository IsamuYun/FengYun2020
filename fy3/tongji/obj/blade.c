// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("厚背刀", ({ "blade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("no_get",1);
                set("no_drop",1);
                set("value", 500);
                set("material", "iron");
                set("long", "这是一厚背大刀，份量大约六、七斤重。\n");
                set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }
        init_blade(75);
        setup();
}

