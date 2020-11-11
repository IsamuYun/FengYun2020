#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"红包"NOR,({"hongbao"}));
	set("long","一个礼庆时用的红包。可以打开它(open)\n");
    set_max_encumbrance(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("weight",3);
		set("closed",1);
	}
}
int is_container()
{
	return 1;
}
void init()
{
        if(this_player()==environment())
                 add_action("do_open","open");
}
int do_open(string arg)
{
	object xijin,ob,me;
	ob=this_object();
	xijin=new("/obj/money/gold");
	xijin->set_amount(ob->query_temp("account"));
	xijin->move(ob);
	me=this_player();
	if ( !arg || arg != "hongbao")
	{
		return notify_fail("你要打开什么？\n");
	}
	message_vision("$N小心翼翼地打开红包......\n",me);
	ob->set("closed",0);
	return 1;
}
int is_closed()
{
        return ((int) this_object()->query("closed"));
}
