inherit ITEM;
inherit F_FOOD;
void create()
{
   set_name("哈密瓜",({"hami gua"}));
   set_weight(200);
   if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个又香又脆的哈密瓜，闻起来都是那么香！\n");
		set("unit", "个");
		set("value", 10);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
