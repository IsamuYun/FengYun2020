// shedan.c - 蛇胆

inherit COMBINED_ITEM;

void create()
{
    	set_name("蛇胆", ({ "shedan" }) );
	if( clonep() )	set_default_object(__FILE__);
	set("unit", "些");
	set("base_unit","个");
	set("long", "治疗神气缺乏的大蛇的胆。吞服（use）后可以恢复你的神气。\n");
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

	message_vision("$N将一个蛇胆慢慢地放到口里，咕的一声吞了下去。\n",me);
	// me->apply_condition("add_sen", 10);
	increasement = 20;
	if( (int)me->query("sen") + increasement < (int)me->query("eff_sen") ) 
		me->set("sen", (int)me->query("sen") + increasement);
	else 
		me->set("sen", (int)me->query("eff_sen"));

	add_amount(-1);        
	return 1;
}
