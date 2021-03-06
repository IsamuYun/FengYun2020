// xiandan.c - 仙丹

inherit COMBINED_ITEM;

void create()
{
    	set_name("仙丹", ({ "xian dan", "dan" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "些");
	set("base_unit", "颗");
	set("long", "世上罕见的圣药。吞服（use）后可以使身体完全恢复。\n");
	set("value", 20000 );
        set("base_weight", 10);
        set_amount(1);

}

void init()
{
	add_action("do_use", "use");
}

int do_use(string arg)
{
	object me;
	int increasement;

	me = this_player();
	if(!id(arg))  return notify_fail("你想要使用什么东西？\n");

	if( me->is_fighting() )	return notify_fail("你现在正在战斗。\n");

	if( me->is_busy() ) return notify_fail("你正忙着呢！\n");
	me->start_busy(1);

	message_vision("$N将一颗仙丹放到口里，慢慢地吞了下去。\n", me );
	me->set("gin", (int)me->query("max_gin"));
	me->set("kee", (int)me->query("max_kee"));
	me->set("sen", (int)me->query("max_sen"));
	me->set("eff_gin", (int)me->query("max_gin"));
	me->set("eff_kee", (int)me->query("max_kee"));
	me->set("eff_sen", (int)me->query("max_sen"));

	me->set("eff_atman", (int)me->query("max_atman"));
	me->set("eff_force", (int)me->query("max_force"));
	me->set("eff_mana", (int)me->query("max_mana"));
	me->set("food", me->max_food_capacity());
	me->set("water", me->max_water_capacity());
	me->set("poison", 0);

	add_amount(-1);        
	return 1;
}
