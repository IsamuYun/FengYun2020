inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("����", ({ "jianghu" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һСƿ������\n");
		set("unit", "ƿ");
		set("value", 2);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	setup();
}
int finish_eat()
{
        set_name("Сƿ����", ({"ping"}));
	set("value",2);
        set("long", "һֻС��ƿ��\n");
        return 1;
}
