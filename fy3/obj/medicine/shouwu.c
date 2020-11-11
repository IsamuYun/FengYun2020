// shouwu.c - 何首乌

inherit COMBINED_ITEM;

void create()
{
    	set_name("何首乌", ({ "shouwu" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "些");
	set("base_unit", "株");
	set("long", "吃多了连头发都可以由白变黑的药。吞服（use）后可以恢复精气。\n");
	set("value", 100 );
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

	me=this_player();
	if(!id(arg))  return notify_fail("你想要使用什么东西？\n");

	if( me->is_fighting() )	return notify_fail("你现在正在战斗。\n");

	if( me->is_busy() ) return notify_fail("你正忙着呢！\n");
	me->start_busy(1);

	message_vision("$N将一株何首乌慢慢地放到口里，很有滋味地吃了下去。\n",me );
	// me->apply_condition("add_eff_gin",2);
	increasement = 5;
	if( (int)me->query("eff_gin") + increasement < (int)me->query("max_gin") ) 
		me->set("eff_gin", (int)me->query("eff_gin") + increasement);
	else 
		me->set("eff_gin", (int)me->query("max_gin"));

	add_amount(-1);        
	return 1;
}
