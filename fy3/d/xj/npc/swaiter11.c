inherit F_VENDOR;
inherit NPC;

void create()
{
        set_name("卖戒指的", ({ "ring seller" }) );
        set("gender", "男性" );
        set("age", 34);
        set("combat_exp", 2000);
        set("long", "一个普普通通的本地人，没有一点起眼的地方。\n");
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/ring1" : 20,
		__DIR__"obj/ring2" : 20,
        ]) );
	setup();
        carry_object(__DIR__"obj/cloth")->wear();
        
}

void init()
{       
        object ob;

        ::init();
        add_action("do_vendor_list", "list");
}
