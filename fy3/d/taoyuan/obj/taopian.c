// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��Ƭ��", ({ "taopian cake", "cake" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ѩ�׵ģ��������Һ�ɫ�ߵ����Ƭ�⡣\n");
		set("unit", "��");
		set("value", 20);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
