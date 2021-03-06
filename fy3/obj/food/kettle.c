// kettle.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("茶壶", ({ "kettle" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个铝制茶壶，可以用来装水。\n");
		set("unit", "个");
		set("value", 50);
		set("max_liquid", 20);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "茶水",
		"remaining": 20,
		"drunk_apply": 6,
	]) );
}
