
inherit NPC;

void create()
{
        set_name("С԰��", ({ "young gardener", "gardener" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "һλ�����С԰��\n");
	set("str", 12);
	set("int", 24);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);

	setup();
	add_money("coin", 50);
        carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/scissors")->wield();
}

