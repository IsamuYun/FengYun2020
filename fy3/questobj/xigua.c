// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("大西瓜", ({ "xigua" }) );
	set_weight(180);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个远近闻名的薄皮沙瓤开封大西瓜。\n");
		set("unit", "个");
                set("value", 0);
                set("food_remaining", 3);
		set("food_supply", 80);
	}
}
