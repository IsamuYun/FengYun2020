inherit ITEM;
inherit F_FOOD;
void create()
{
   set_name("���Ѹ�",({"putaogan"}));
   set_weight(80);
   if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������������Ǻ�˵����Ѹ�\n");
		set("unit", "��");
		set("value", 35);
		set("food_remaining", 3);
		set("food_supply", 16);
	}
}
