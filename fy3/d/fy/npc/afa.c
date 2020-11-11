// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����", ({ "afa" }) );
	set("gender", "����" );
	set("age", 35);
	set("long",
		"����ܰ����㿴���尢��������\n");
	set("combat_exp", 50);
	set("attitude", "friendly");
		  set_temp("kf_tufei",1);
        set("pursuer", 1);
set("per",30);
	set("vendor_goods", ([
		"/u/resort/obj/bblade" : 20,
	]) );
	set_skill("unarmed",5);
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
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0:
message_vision("$N��$n˵�����֪��֪������Ϭ������������Ī�ö�����ľ����Ļ�������\n",this_object(),ob);
			break;
	}
}
