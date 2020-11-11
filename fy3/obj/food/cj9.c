inherit ITEM;
void create()
{
        set_name("山参鸡段", ({ "jiduan"}) );
        set_weight(350);
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("long", "一只由某人亲手烹饪的山参鸡段，不但让你胃口大开，还有一定的药用价值!\n");
           set("unit", "只");
           set("value", 10000);
		   set("pet_kee",128000);
        }
        setup();
}
void init()
{
        if(this_player()==environment())
        add_action("eat_dan","eat");
}
int eat_dan(string arg)
{
        object me;
        me = this_player();

		if (arg == "jiduan")
		{
			if (me->query_temp("no_eat"))
			{
				return notify_fail("你目前的状态不能使用任何药品。\n");
			}
		me->set("kee",me->query("max_kee"));
		me->set("eff_kee",me->query("max_kee"));
        message_vision("$N一口气将" + this_object()->query("name") + "吞了下去。\n", this_player());
        write("你感觉气血恢复了。\n");
		me->start_busy(4-me->query("save_for_eat"));
        destruct(this_object());

	}
        return 0;
}
