// jinchuangyao.c - 金创药

inherit COMBINED_ITEM;

void create()
{
	set_name("金创药", ({ "jinchuang yao", "yao" }) );
	if( clonep() )	set_default_object(__FILE__);
	set("unit", "些");
	set("base_unit","颗");
	set("long", "江湖人士随身必备的医治刀剑之伤的药，敷用（use）之后对伤势会有一定的效果。\n");
	set("value", 100);
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
	if(!id(arg) ) return notify_fail("你想要用什么东西？\n");

	if( me->is_fighting() )	return notify_fail("你现在正在战斗。\n");

	if( me->is_busy() ) return notify_fail("你正忙着呢！\n");
	me->start_busy(1);

	message_vision("$N将金创药用手捏碎，小心地就着伤口敷了上去。\n",me);
	// me->apply_condition("add_eff_kee", 2);
	increasement = 5;
	if( (int)me->query("eff_kee") + increasement < (int)me->query("max_kee") ) 
		me->set("eff_kee", (int)me->query("eff_kee") + increasement);
	else 
		me->set("eff_kee", (int)me->query("max_kee"));

	add_amount(-1);        
	return 1;
}
