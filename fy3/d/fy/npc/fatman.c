// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("������", ({ "fatman" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "һ���װ����ֵİ����ӣ�\n");
	set("combat_exp", 5);
        set("chat_chance", 2);
        	  set_temp("kf_tufei",19);
        set("pursuer", 1);
set("chat_msg", ({
                "������ָ���㼥Ц�����㣮������һ��ֻ�������\n",
		"�����Ӻߵ�����Բ֮ҹ���Ͻ�֮�ۣ�Ҷ����Ӯ���ˣ���\n",
        }) );

        set("attitude", "friendly");
        set("rank_info/respect", "�ָ�");
        set("vendor_goods", ([
                __DIR__"obj/dogmed":10,
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{
        add_action("do_vendor_list", "list");
}

