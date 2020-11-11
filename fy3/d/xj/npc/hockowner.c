#include <ansi.h>

inherit NPC;
inherit F_PAWNOWNER;
inherit F_VENDOR;
void create()
{
	set_name("ľ����", ({ "mulati" }) );
	set("gender", "����" );
	set("age", 67);
	set("title", "�����ϰ���");
	set("combat_exp", 500);
	set("attitude", "friendly");
        set("richness",50000);
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
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
	add_action("do_vendor_list","list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	say( "ľ����̧ͷ����һ�ۣ�����\n");
}
