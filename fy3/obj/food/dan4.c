// writted by Tiandi
inherit ITEM;
void create()
{
        set_name("金香玉丹", ({ "jxdan"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("long","一颗由某人亲手炼丹而来的金香玉丹。据说食用之后可以恢复适量法力。\n");
           set("unit", "颗");
           set("value",100);
		   set("pet_gin",1000);
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
	if (arg == "jxdan")
	{
       if (me->query_temp("no_eat"))
			{
				return notify_fail("你目前的状态不能使用任何药品。\n");
			}
        me ->add("mana",500);
		if (me->query("mana")>me->query("max_mana"))
		{
			me->set("mana",me->query("max_mana"));
		}
        message_vision("$N一口气将" + this_object()->query("name") + "吞了下去。\n", this_player());
        write("你感觉法力恢复了。\n");
		me->start_busy(4-me->query("save_for_eat"));
        destruct(this_object());
	}
        return 0;
}
