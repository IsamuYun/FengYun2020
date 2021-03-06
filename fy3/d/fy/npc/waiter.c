// waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("店小二", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 5);
		  set_temp("kf_tufei",64);
        set("pursuer", 1);
set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		"/obj/example/wineskin" : 10,
		"/obj/example/dumpling" : 30,
      	"/obj/example/chicken_leg" : 40
		]) );
	set("inquiry", ([ 
			"go" : "小店现在和各大驿站合作，新开驿站服务。十级以下免费使用。\n" 
		]));
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
	switch( random(3) ) {
		case 0:
                        say( "\n店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
    + "，欢迎光临风云的世界，希望你能玩的开心。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                  + "，您需要点什么？\n");
			break;
		case 2:
			say( "店小二说道：这位" + RANK_D->query_respect(ob)
        + "，现在没什么新消息。。\n");
			break;
	}
}
