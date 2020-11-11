inherit ITEM;
void create()
{
        set_name("神效丹", ({ "third dan"}) );
        set_weight(350);
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("long", "食用后一小时内某些任务获得的奖励成三倍效果!\n");
           set("unit", "颗");
           //set("value", 10000);
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

		if (arg == "third dan")
		{
		me->set("doubletype", 2);
		me->set("doubletime", (int) time()+ 3600);
        message_vision("$N一口气将" + this_object()->query("name") + "吞了下去。\n", this_player());
        write("你感觉精神十分活跃。\n");
        destruct(this_object());

	}
        return 0;
}
