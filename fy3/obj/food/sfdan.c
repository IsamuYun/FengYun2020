// writted by Tiandi
inherit ITEM;
void create()
{
    set_name("十方化潜丹", ({ "sfdan"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("long","一颗由某人亲手炼丹而来的十方化潜丹。据说食用之后可以使人将一部分经验转化为潜能。\n");
           set("unit", "颗");
           set("value",50000);
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
        int exp,pot;	
        me = this_player();
	if (arg == "sfdan")
	{
        exp = (int)me->query("combat_exp");
        if (exp < 2000000 ) 
           return notify_fail("你的经验还不足以使用此丹药。\n");
        me ->set("combat_exp",exp - 100000);
        me ->add("potential",10000);
        message_vision("$N一口气将" + this_object()->query("name") + "吞了下去。\n", this_player());
        write("你感觉潜能增加了！\n");
        destruct(this_object());
	}
        return 0;
}
