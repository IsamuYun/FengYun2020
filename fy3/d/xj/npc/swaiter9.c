inherit F_VENDOR;
inherit NPC;

void create()
{
        set_name("����̺��", ({ "ditan seller" }) );
        set("gender", "����" );
        set("age", 34);
        set("combat_exp", 2000);
        set("long", "һ������ͨͨ�ı����ˣ�û��һ�����۵ĵط���\n");
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/ditan" : 20,
        ]) );
	setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{       
        ::init();
        add_action("do_vendor_list", "list");
}
