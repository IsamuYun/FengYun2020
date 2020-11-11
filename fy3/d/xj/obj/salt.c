inherit ITEM;

void create()
{
        set_name("盐巴", ({ "salt rock", "盐巴"}) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "一块盐巴\n");
	    set("unit","块");
	 set("value",10);
	}
}

void init()
{
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("指令格式: pour 盐巴 in <容器>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("你身上没有 " + what + " 这样东西。\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "里什麽也没有，先装些水才行。\n");

	ob->set("liquid", ([
		"type": "water",
		"name": "盐水",
		]));
	message_vision("$N将" + name() + "放进" + ob->name() 
		+ "，摇晃了几下。\n", this_player());

	destruct(this_object());
	return 1;
}
