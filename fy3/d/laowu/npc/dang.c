// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�ƿ���", ({ "tang" }) );
	set("gender", "Ů��" );
	set("age", 21);
	set("long",
		"��λ�ƿ���Ц����������㡣\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/egg":20,
		"/obj/example/wineskin":10,

	]) );
	set_skill("unarmed",50);
	set_skill("tenderzhi",50);
	set_skill("dodge",50);
	set_skill("stormdance",50);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/bigcloth")->wear();
}
void init()
{
        add_action("do_vendor_list", "list");
}

