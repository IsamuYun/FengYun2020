// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("屠刀", ({ "tudao" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("material", "iron");
                set("long", "这是一柄杀猪专用的屠刀，十分锋利，上面模糊的刻着--屠记肉铺。\n");
                set("wield_msg", "$N抽出一把粘满血腥的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插回腰间。\n");
        }
        init_blade(40);
        setup();
}
