// big-bag.c

inherit ITEM;

void create()
{
	set_name("麻袋", ({ "big bag", "bag" }) );
	set_weight(1000);
	set_max_encumbrance(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
		set("long", "这是一口寻常的麻袋，可以用来装一些杂物。\n");
		set("value", 100);
    };
}

int is_container() { return 1; }
