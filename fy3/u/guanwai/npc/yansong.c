
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����", ({ "yan song", "song" }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("per", 30);
	set("long",
		"�����Ǹ��׸�ɮ�ĵ�������ӡ�\n");
        create_family("������", 21, "����");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set_skill("iron-cloth", 100);
	set_skill("jin-gang", 10);
	set_skill("unarmed", 100);
	set_skill("bloodystrike", 100);
	map_skill("unarmed", "bloodystrike");
	map_skill("iron-cloth", "jin-gang");
        set("inquiry", ([
                "������": "��....������ӣ��������㡣\n",
                "��������": "��....����������أ����������ڴ�Į���ˡ�\n",
        ]) );
	set("vendor_goods", ([
		__DIR__"obj/fake-tooth":30,
	]) );
	setup();
	carry_object(__DIR__"obj/redclothh")->wear();
}
