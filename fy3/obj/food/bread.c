// bread.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("馒头", ({ "bread" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷、热腾腾的白面馒头。\n");
		set("unit", "个");
		set("value", 10);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}
