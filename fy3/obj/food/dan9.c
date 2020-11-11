// writted by Tiandi
inherit ITEM;
void create()
{
        set_name("返生丹", ({ "fsdan"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("long","一颗由某人亲手炼丹而来的返生丹。据说食用之后可以使人恢复活力。\n");
           set("unit", "颗");
           set("value",100);
		   set("pet_gin",32000);
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
 	if (arg == "fsdan")
	{
       me ->add("lifetili",200);
	if (me->query("lifetili") >  me->query("max_lifetili"))
		me->set("lifetili",me->query("max_lifetili"));
        message_vision("$N一口气将" + this_object()->query("name") + "吞了下去。\n", this_player());
        write("你感觉活力增加了。\n");
		me->start_busy(4-me->query("save_for_eat"));
        destruct(this_object());
	}
        return 0;
}
