inherit F_VENDOR;
inherit NPC;

void create()
{
        set_name("����ָ��", ({ "ring seller" }) );
        set("gender", "����" );
        set("age", 34);
        set("combat_exp", 2000);
        set("long", "һ������ͨͨ�ı����ˣ�û��һ�����۵ĵط���\n");
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
