// gold.c
#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(HIY "南宫金票" NOR, ({"gold"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "gold");
                set("long", HIY "黄澄澄的金子，人见人爱的金子，啊～～金子！\n" NOR);
		set("unit", "些");
		set("base_value", 10000 );
		set("base_unit", "两");
		set("base_weight", 37);
	}
        set_amount(100+random(100));
}

