inherit F_VENDOR;
inherit NPC;

void create()
{
        set_name("�������ӵ�", ({ "bao seller" }) );
        set("gender", "����" );
        set("age", 34);
        set("combat_exp", 1000);
        set("long", "һ��������źܶ���ӵ��ˣ�����������װ���ӵģ���������ð���͹⡣\n");
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/baozi" : 20,
        ]) );
	setup();
        carry_object(__DIR__"obj/cloth")->wear();
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
	say( "�������ӵĸ߽е���ţ��������ӣ��������ֺóԣ���\n");
}
