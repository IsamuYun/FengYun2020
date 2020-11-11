// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("杂货店老板", ({ "seller" }) );
	set("gender", "男性" );
	set("age", 34);
	set("long",
		"一看模样,典型的新疆人,这位杂货店老板正坐在柜台后面算帐，
不时地抬头望一眼门外。\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"/obj/paper_seal":100,
		"/obj/dust":10,
                    "/d/dali/obj/jiduan" : 20,
              "/d/dali/obj/jiudai" : 10,
              "/obj/guo" : 10,
              "/obj/medicine" : 10,

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
			say( "杂货店老板笑咪咪地问道：这位" + RANK_D->query_respect(ob)
				+ "，需要点儿什么？\n");
			break;
		case 1:
			say( "杂货店老板正在低头算帐，并没注意到" + ob->name() + "进来。\n");
			break;
	}
}
