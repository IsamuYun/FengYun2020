// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��ҩ��", ({ "medseller" }) );
        set("gender", "����" );
        set("age", 30);
        set("long",
                "һ�������õ���ҩ�ĵĻ��\n");
	set("combat_exp", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ҩ�ĸ߽е���ม��������ϰ�ҩ����\n",
                "��ҩ�ĸ߽е���ม����������衫��\n",
                "��ҩ�ĸ߽е���ม���������衫��\n",

        }) );
	  set_temp("kf_tufei",15);
        set("pursuer", 1);

        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/sendrug":11,
                __DIR__"obj/keedrug":30,
                __DIR__"obj/gindrug":11,
			 __DIR__"obj/jiedu":111,
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{
        add_action("do_vendor_list", "list");
}

