#include <ansi.h>

inherit NPC;
inherit F_PAWNOWNER;
inherit F_VENDOR;
void create()
{
	set_name("木拉提", ({ "mulati" }) );
	set("gender", "男性" );
	set("age", 67);
	set("title", "当铺老板娘");
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
	say( "木拉提抬头看了一眼．．．\n");
}
