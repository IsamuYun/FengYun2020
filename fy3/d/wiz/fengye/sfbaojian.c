#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
    set_name("尚方宝剑", ({ "sfbaojian" }) );
        set_weight(8000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "柄");
            set("material", "stone");
            set("long", "皇上誉赐的一把宝剑。\n");
set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插回鞘内。\n");
           set("weapon_prop/personality",2);
          }
        init_sword(90);
    setup();
}
