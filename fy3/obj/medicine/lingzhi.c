// lingzhi.c - 灵芝

inherit COMBINED_ITEM;

void create()
{
    	set_name("灵芝", ({ "lingzhi" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "些");
	set("base_unit", "株");
	set("long", "大补之品。吞服（use）后可以恢复神气。\n");
	set("value", 500 );
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

	message_vision("$N将一株灵芝慢慢地放到口里，很有滋味地吃了下去。\n", me );
	// me->apply_condition("add_eff_sen", 10);
	increasement = 20;
	if( (int)me->query("eff_sen") + increasement < (int)me->query("max_sen") ) 
		me->set("eff_sen", (int)me->query("eff_sen") + increasement);
	else 
		me->set("eff_sen", (int)me->query("max_sen"));

	add_amount(-1);        
	return 1;
}
