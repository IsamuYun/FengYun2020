// waiter.c
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);

void create()
{
	set_name("老裁缝", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 52);
	set("long",
		"这位老裁缝正笑咪咪地忙著，还不时的擦一擦自己的老花眼。\n");
	set("combat_exp", 5);
		  set_temp("kf_tufei",9);
        set("pursuer", 1);
set("attitude", "friendly");
	setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
			say( "老裁缝笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，需要做什么防具都请自己动手吧。\n");
			break;
		case 1:
			say( "老裁缝愁眉苦脸说道：这位" + RANK_D->query_respect(ob)
				+ "，有什么活你自己做吧，我已经干不动了。\n");
			break;
	}
}
