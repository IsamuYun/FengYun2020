inherit ITEM;
inherit F_FOOD;
void create()
{
   set_name("�����⴮",({"fried sheep meat", "sheep", "meat"}));
   set_weight(200);
   if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����������������������⴮���ó԰���\n");
		set("unit", "��");
		set("value", 25);
		set("food_remaining", 3);
		set("food_supply", 16);
	}
}
