// chicken_leg.c
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������Ĵ��", ({ "fried turkey", "turkey"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻ����������Ĵ�𼦣��ж��ڿ��֣���\n");
		set("unit", "ֻ");
		set("food_remaining", 40);
		set("food_supply", 100);
	}
}
