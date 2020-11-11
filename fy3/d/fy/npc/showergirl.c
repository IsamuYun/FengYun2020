// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("СѾ��", ({ "yahuan" }) );
	set("gender", "Ů��" );
	set("age", 14);
	set("title", "�绨����");
	set("long",
		"һ��������а��СѾ��\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
		  set_temp("kf_tufei",53);
        set("pursuer", 1);
set("per",30);
	set("vendor_goods", ([
		__DIR__"obj/white_towel":11,

	]) );
	set_skill("unarmed",5);
	set_skill("tenderzhi",5);
	set_skill("dodge",5);
	set_skill("stormdance",5);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/green_cloth")->wear();

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
message_vision("$N�ڰ�æ��̧��ͷ����$nһ�ۡ�\n",this_object(),ob);
			break;
	}
}
