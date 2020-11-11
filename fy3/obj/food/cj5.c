inherit ITEM;
void create()
{
        set_name("金香圈", ({ "quan"}) );
        set_weight(350);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("long","一只由某人亲手烹饪的金香圈，香浓的味道传了好远。\n");
           set("unit", "个");
           set("value", 100);
		   set("pet_kee",8000);
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

		if (arg == "quan")
		{
			if (me->query_temp("no_eat"))
			{
				return notify_fail("你目前的状态不能使用任何药品。\n");
			}
        me ->add("kee",2200);
		if (me->query("kee")>me->query("max_kee"))
		{
			me->set("kee",me->query("max_kee"));
		}
        message_vision("$N一口气将" + this_object()->query("name") + "吞了下去。\n", this_player());
        write("你感觉气血恢复了。\n");
		me->start_busy(4-me->query("save_for_eat"));
        destruct(this_object());

	}
        return 0;
}
