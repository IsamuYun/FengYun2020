inherit ITEM;
void create()
{
        set_name("盟主任务丹", ({ "mengzhu dan"}) );
        set_weight(350);
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("long", "食用后一小时内做盟主任务会自动带你到剿灭的天宗门徒所在地.\n");
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

		if (arg == "mengzhu dan")
		{
		me->set("mengzhuauto", (int) time()+ 3600);
        message_vision("$N一口气将" + this_object()->query("name") + "吞了下去。\n", this_player());
        write("你对盟主的任务充满了信心。\n");
        destruct(this_object());

	}
        return 0;
}
