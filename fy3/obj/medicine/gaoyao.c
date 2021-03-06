// gaoyao.c - 狗皮膏药

inherit COMBINED_ITEM;

void create()
{
	set_name("狗皮膏药", ({ "gaoyao" }) );
	if( clonep() )	set_default_object(__FILE__);
	set("unit", "些");
	set("base_unit","帖");
	set("long","治疗跌打的狗皮膏药。如果你被打得内伤，不妨贴一帖（use）试试。\n");
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
	if(!id(arg))  return notify_fail("你想要用什么东西？\n");

	if( me->is_fighting() )	return notify_fail("你现在正在战斗。\n");

	if( me->is_busy() ) return notify_fail("你正忙着呢！\n");
	me->start_busy(1);

	message_vision("$N将一帖狗皮膏药“啪”地一声往身上红肿的部位贴了上去。\n",me);
	// me->apply_condition("add_kee", 10);
	increasement = 20;
	if( (int)me->query("kee") + increasement < (int)me->query("eff_kee") ) 
		me->set("kee", (int)me->query("kee") + increasement);
	else 
		me->set("kee", (int)me->query("eff_kee"));

	add_amount(-1);        

	return 1;
}
