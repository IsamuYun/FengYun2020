// by tie@fengyun

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����", ({ "big cabbage" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ˮ����Ĵ����\n");
		set("unit", "��");
		set("value", 25);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
