// worker.c

inherit NPC;

void create()
{
        set_name("采花妞", ({ "little girl", "girl" }) );
        set("gender", "女性" );
        set("age", 9);
        set("long", "天真的小女孩正在玩耍着 \n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_skill("unarmed", 40);
        set_skill("parry", 45);
	set_skill("dodge", 100);
	set_skill("throwing", 50);

        set("inquiry", ([
		"小娟" : "这要到黑松山去问。", 
        ]) );

	setup();
	add_money("coin", 15);
        carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/flower")->wield();
}

