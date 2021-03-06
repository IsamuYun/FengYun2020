// baiyao.c - 白药

inherit COMBINED_ITEM;

void create()
{
    	set_name("白药", ({ "baiyao" }) );
	if( clonep())  set_default_object(__FILE__);
	set("unit", "些");
	set("base_unit", "包");
	set("long", "治疗刀剑内伤的圣药。吞服（use）后可以恢复血气。\n");
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

	message_vision("$N将一包白药放到口里，慢慢地吞了下去。\n", me );
	// me->apply_condition("add_eff_kee", 10);
	increasement = 20;
	if( (int)me->query("eff_kee") + increasement < (int)me->query("max_kee") ) 
		me->set("eff_kee", (int)me->query("eff_kee") + increasement);
	else 
		me->set("eff_kee", (int)me->query("max_kee"));

	add_amount(-1);        
	return 1;
}
