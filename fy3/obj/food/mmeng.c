// writted by Tiandi
inherit ITEM;
void create()
{
        set_name("消盟丹", ({ "mmeng"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("long","一颗由具有神奇功效的神丹。据说食用之后可以消除已经完成的盟主任务的数量。\n");
           set("unit", "颗");
           set("value",100);
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
	if (arg == "mmeng")
	{
        if (me->query_temp("no_eat"))
			{
				return notify_fail("你目前的状态不能使用任何药品。\n");
			}
        if (me->query("level")>80)
			{
				return notify_fail("你目前的状态再怎么吃也没有用了。\n");
			}
        message_vision("$N一口气将" + this_object()->query("name") + "吞了下去。\n", this_player());
        write("你感觉又能去尝试奸细任务了。\n");
		me->add("mengzhujob",-50);
		if (me->query("mengzhujob")< 0)
		{
			me->set("mengzhujob",0);
		}
		me->start_busy(4-me->query("save_for_eat"));
        destruct(this_object());
	}
        return 0;
}
