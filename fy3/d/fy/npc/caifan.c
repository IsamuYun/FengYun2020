// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���˵�", ({ "caifan" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "һ��Ϊ��������ձ�����С���ˣ�\n");
	set("combat_exp", 5);
        set("attitude", "friendly");
        	  set_temp("kf_tufei",8);
        set("pursuer", 1);
set("rank_info/respect", "�϶���");
        set("chat_chance", 3);
        set("chat_msg", ({
                "���˵�Ц������һ��������ɣ��߲�һ��Ҷ�³�ʤ����\n",
        }) );

        set("vendor_goods", ([
                __DIR__"obj/smallvege":11,
                __DIR__"obj/bigvege":22,
                __DIR__"obj/midvege":22,

        ]) );
        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
}
