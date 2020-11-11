inherit F_VENDOR;
inherit NPC;

void create()
{
        set_name("卖花帽的", ({ "mao seller" }) );
        set("gender", "男性" );
        set("age", 34);
        set("combat_exp", 2000);
        set("long", "一个普普通通的本地人，没有一点起眼的地方。\n");
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/hat" : 20,
        ]) );
	setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{       
        ::init();
        add_action("do_vendor_list", "list");
}