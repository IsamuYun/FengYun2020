inherit F_VENDOR;
inherit NPC;

void create()
{
        set_name("���⳵���ӵ�", ({ "xing seller" }) );
        set("gender", "Ů��" );
        set("age", 34);
        set("combat_exp", 2000);
        set("long", "һ������ͨͨ�ı����ˣ�û��һ�����۵ĵط���\n");
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/xing" : 20,
        ]) );
	setup();
        carry_object(__DIR__"obj/skirt")->wear();
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
	say( "�����ӵĸ߽е����⳵���ӣ������ʵ��\n");
}
