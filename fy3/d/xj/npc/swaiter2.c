inherit F_VENDOR;
inherit NPC;

void create()
{
        set_name("��ץ����", ({ "fan seller" }) );
        set("gender", "����" );
        set("age", 45);
        set("combat_exp", 2000);
        set("long", "������ĸߴ󣬿������ƺ�����������\n");
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
	say( "��ץ���ĸ߽е������⼸��ץ���ˣ��ٲ����û��ඣ�\n");
}
