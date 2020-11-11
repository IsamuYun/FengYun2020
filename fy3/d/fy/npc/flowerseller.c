// waiter.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("������", ({ "huaman" }) );
	set("gender", "����" );
	set("age", 41);
	set("title", BLU "����" NOR);
	set("long",
		"��λ�ϰ�������¶�������Ц�ݡ�\n");
	set("combat_exp", 500000);
		  set_temp("kf_tufei",20);
        set("pursuer", 1);
set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/purple_flower":30,
                __DIR__"obj/red_flower":25,
                __DIR__"obj/yellow_flower":33,
                __DIR__"obj/blue_flower":44,
                __DIR__"obj/white_flower":14,
                __DIR__"obj/black_flower":10,
	]) );
	set_skill("unarmed",50);
	set_skill("dodge",50);
	setup();
        carry_object(__DIR__"obj/fycloth")->wear();
       if (!random(2)) carry_object("questobj/obj/txmuliao");
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
	switch( random(5) ) {
		case 0:
message_vision("$NЦ��˵�����������ʻ��䣬��Щ��ȥ����������˰ɡ�\n",this_object(),ob);
			break;
		case 1:
message_vision("$NЦ�����˵������λ"+RANK_D->query_respect(ob)+
"Ҫ��ʲô������\n",this_object(),ob);
			break;
	}
}
