
inherit NPC;

void create()
{
	set_name("���²���", ({ "zhang ni", "ni"}) );
	set("gender", "Ů��" );
	set("age", 25);
	set("str", 20);
	set("long", @LONG
һ�������µĲ��ᡣ
LONG
);
	set("attitude", "peaceful");

        set("combat_exp", 600);
        create_family("������", random(4)+22, "����");
        set_skill("unarmed", 50+random(10));
        set_skill("bloodystrike", random(50)+20);
        set_skill("force", 40);
	map_skill("unarmed", "bloodystrike");
	set_skill("iron-cloth", 40+random(10));
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );

	setup();

        carry_object(__DIR__"obj/redcloth2")->wear();
}
