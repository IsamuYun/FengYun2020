#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( "带鞘的尚方宝剑", ({ "gswords" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把当今皇上御赐的尚方宝剑。\n");
		set("material", "steel");
                set("value", 10000); 
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入古剑鞘。\n");
	}
	init_sword(45);
	setup();
}
