#include <weapon.h>

inherit SWORD;
void create()
{
        set_name("凝碧剑", ({ "ningsword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
	               set("material", "iron");
 set("long", "一个枯梅大师常配带的剑。\n");
                set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插回鞘内。\n");
        }
        init_sword(75);
        setup();
}

