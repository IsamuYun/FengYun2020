// bread.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ͷ", ({ "bread" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������硢�����ڵİ�����ͷ��\n");
		set("unit", "��");
		set("value", 10);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}
