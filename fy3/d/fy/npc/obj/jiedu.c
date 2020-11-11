// medicine.c

inherit ITEM;

void create()
{
	set_name("解毒丹",({"jiedu"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "一颗解毒丹， 可以用（ｕｓｅ）来解毒 。\n");
	    set("unit","颗");
	    set("value", 10000);
	}
}

void init()
{
  if(this_player()==environment())
	add_action("apply_medicine","use");
}

int apply_medicine(string arg)
{
	if (arg == "jiedu")
	{
	if(this_player()->is_fighting())
	    return notify_fail("战斗中不能用药！！\n");
	    
	message_vision("$N用解毒丹解毒．\n",this_player());
	this_player()->set_temp("poison_del",1);
	destruct(this_object());
	return 1;
	}
	return 0;
}


