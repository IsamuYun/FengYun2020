// jingqiwan.c - 精气丸

inherit COMBINED_ITEM;

void create()
{
    	set_name("精气丸", ({ "jingqi wan", "wan" }) );
	if( clonep() )	set_default_object(__FILE__);
	set("unit", "些");
	set("base_unit","颗");
	set("long", "治疗精气缺乏的灵丹妙药。吞服（use）后可以恢复你的精气。\n");
	set("value", 50);
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

	message_vision("$N将一棵精气丸慢慢地放到口里，咕的一声吞了下去。\n",me);
	// me->apply_condition("add_gin", 10);
	increasement = 20;
	if( (int)me->query("gin") + increasement < (int)me->query("eff_gin") ) 
		me->set("gin", (int)me->query("gin") + increasement);
	else 
		me->set("gin", (int)me->query("eff_gin"));

	add_amount(-1);        
	return 1;
}
