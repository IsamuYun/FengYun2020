// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������", ({ "kao baozi" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������硢����ð�͵Ĵ���ӡ�\n");
		set("unit", "��");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 40);
	}
}