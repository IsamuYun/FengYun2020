// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("������", ({ "xigua" }) );
	set_weight(180);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��Զ�������ı�Ƥɳȿ��������ϡ�\n");
		set("unit", "��");
                set("value", 0);
                set("food_remaining", 3);
		set("food_supply", 80);
	}
}
