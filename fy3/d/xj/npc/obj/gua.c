inherit ITEM;
inherit F_FOOD;
void create()
{
   set_name("���ܹ�",({"hami gua"}));
   set_weight(200);
   if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������ִ�Ĺ��ܹϣ�������������ô�㣡\n");
		set("unit", "��");
		set("value", 10);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
