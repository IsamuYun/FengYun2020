inherit ITEM;
inherit F_FOOD;
void create()
{
   set_name("葡萄干",({"putaogan"}));
   set_weight(80);
   if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一把闻起来都甜得呛人的葡萄干\n");
		set("unit", "把");
		set("value", 35);
		set("food_remaining", 3);
		set("food_supply", 16);
	}
}
