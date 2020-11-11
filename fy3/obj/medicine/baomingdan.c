// baomingdan.c - 天王保命丹

inherit COMBINED_ITEM;

void create()
{
    	set_name("天王保命丹", ({ "baoming dan", "dan" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "些");
	set("base_unit", "颗");
	set("long", "难见的圣药。吞服（use）后可以使身体恢复。\n");
	set("value", 3000 );
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

	message_vision("$N将一颗天王保命丹放到口里，慢慢地吞了下去。\n", me );
/*
	me->apply_condition("add_gin", 20);
	me->apply_condition("add_eff_gin", 20);
	me->apply_condition("add_kee", 20);
	me->apply_condition("add_eff_kee", 20);
	me->apply_condition("add_sen", 20);
	me->apply_condition("add_eff_sen", 20);
*/
	increasement = 50;
	if( (int)me->query("gin") + increasement < (int)me->query("eff_gin") ) 
		me->set("gin", (int)me->query("gin") + increasement);
	else 
		me->set("gin", (int)me->query("eff_gin"));
	if( (int)me->query("eff_gin") + increasement < (int)me->query("max_gin") ) 
		me->set("eff_gin", (int)me->query("eff_gin") + increasement);
	else 
		me->set("eff_gin", (int)me->query("max_gin"));
	if( (int)me->query("kee") + increasement < (int)me->query("eff_kee") ) 
		me->set("kee", (int)me->query("kee") + increasement);
	else 
		me->set("kee", (int)me->query("eff_kee"));
	if( (int)me->query("eff_kee") + increasement < (int)me->query("max_kee") ) 
		me->set("eff_kee", (int)me->query("eff_kee") + increasement);
	else 
		me->set("eff_kee", (int)me->query("max_kee"));
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
