#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIW"小李飞刀"NOR, ({ "feidao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("material", "iron");
                set("long", "这是一把李寻环常用的飞刀，薄薄的刀身发出耀眼的光芒。\n");
                set("wield_msg", "只见白光一闪，$N手中多出一把薄薄的飞刀。\n");
                set("unwield_msg", "$N仔细的把飞刀擦干净收了起来。\n");
        }
        init_blade(100);
        setup();
}
