// writted by Tiandi
inherit ITEM;
void create()
{
        set_name("雀香仙丹", ({ "qxdan"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("long","一颗由某人亲手炼丹而来的雀香仙丹。据说食用之后可以恢复大部分消耗的内力。\n");
           set("unit", "颗");
           set("value",100);
		   set("pet_gin",2000);
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
	if (arg == "qxdan")
	{
		if (me->query_temp("no_eat"))
			{
				return notify_fail("你目前的状态不能使用任何药品。\n");
			}
        me ->add("force",1500);
		if (me->query("force")>me->query("max_force"))
		{
			me->set("force",me->query("max_force"));
		}
        message_vision("$N一口气将" + this_object()->query("name") + "吞了下去。\n", this_player());
        write("你感觉内力恢复了。\n");
		me->start_busy(4-me->query("save_for_eat"));
        destruct(this_object());
	}
        return 0;
	}
