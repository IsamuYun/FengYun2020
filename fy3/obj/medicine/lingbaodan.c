// lingbaodan.c - 九转灵宝丹

inherit COMBINED_ITEM;

void create()
{
    	set_name("九转灵宝丹", ({ "lingbao dan", "dan" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "些");
	set("base_unit", "颗");
	set("long", "难见的圣药。吞服（use）后可以恢复精气。\n");
	set("value", 5000 );
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

	message_vision("$N将一颗九转灵宝丹放到口里，慢慢地吞了下去。\n", me );
	// me->apply_condition("add_gin", 50);
	// me->apply_condition("add_eff_gin", 50);
	increasement = 100;
	if( (int)me->query("gin") + increasement < (int)me->query("eff_gin") ) 
		me->set("gin", (int)me->query("gin") + increasement);
	else 
		me->set("gin", (int)me->query("eff_gin"));
	if( (int)me->query("eff_gin") + increasement < (int)me->query("max_gin") ) 
		me->set("eff_gin", (int)me->query("eff_gin") + increasement);
	else 
		me->set("eff_gin", (int)me->query("max_gin"));

	add_amount(-1);        
	return 1;
}
