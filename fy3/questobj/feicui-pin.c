#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIG "翡翠珠花" NOR, ({ "feicui-pin"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一只如秋水般的碧绿珠花。\n");
		set("unit", "只");
		set("value", 200000);
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 5);
                set("armor_prop/intelligence",5);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上，晃动不定的翠绿光华让你瞳孔放大。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");


	}
	setup();
}

