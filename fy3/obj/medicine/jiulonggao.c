// jiulonggao.c - 回阳九龙膏

inherit COMBINED_ITEM;

void create()
{
    	set_name("回阳九龙膏", ({ "jiulong gao", "gao" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "些");
	set("base_unit", "块");
	set("long", "难见的圣药。吞服（use）后可以恢复神气。\n");
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

	message_vision("$N将一块回阳九龙膏放到口里，慢慢地吞了下去。\n", me );
	// me->apply_condition("add_sen", 50);
	// me->apply_condition("add_eff_sen", 50);
	increasement = 100;
	if( (int)me->query("sen") + increasement < (int)me->query("eff_sen") ) 
		me->set("sen", (int)me->query("sen") + increasement);
	else 
		me->set("sen", (int)me->query("eff_sen"));
	if( (int)me->query("eff_sen") + increasement < (int)me->query("max_sen") ) 
		me->set("eff_sen", (int)me->query("eff_sen") + increasement);
	else 
		me->set("eff_sen", (int)me->query("max_sen"));

	add_amount(-1);        
	return 1;
}
