// waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("杂货商人", ({ "trader" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位商人一看就是奸诈狡猾的样子。\n");
	set("combat_exp", 500000);
         set("attitude", "friendly");
	set("rank_info/respect", "老板");
	set("vendor_goods", ([
		"/d/wiz/fyup/obj/qh1" : 10,
		"/d/wiz/fyup/obj/sheet" : 30,
		"/obj/glass" : 50,          
	]) );
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
                        say( "\n杂货商人笑咪咪地说道：这位" + RANK_D->query_respect(ob)
    + "，本人的卖的东西一向货真价值，不信地话您来瞧瞧吧。\n");
			break;
		case 1:
			say( "\n杂货商人说道：最近宝石缺货，可怎么办才好啊？\n");
			break;
	}
}
