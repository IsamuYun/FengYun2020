inherit F_VENDOR;
inherit NPC;

void create()
{
        set_name("卖抓饭的", ({ "fan seller" }) );
        set("gender", "男性" );
        set("age", 45);
        set("combat_exp", 2000);
        set("long", "这人身材高大，看起来似乎很有力气。\n");
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/fan" : 20,
        ]) );
	setup();
        carry_object(__DIR__"obj/ditan")->wear();
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
	say( "卖抓饭的高叫道：就这几份抓饭了，再不买就没有喽！\n");
}
