inherit F_VENDOR;
inherit NPC;

void create()
{
        set_name("�����⴮��", ({ "meat seller" }) );
        set("gender", "����" );
        set("age", 34);
        set("combat_exp", 200);
        set("long", "����������ζ������\n");
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/meat" : 20,
        ]) );
	setup();
        carry_object(__DIR__"obj/hat")->wear();
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
	say( "�����⴮�ĸ߽е����������ȵĿ����⴮ѽ����\n");
}
