#include <ansi.h>
inherit NPC;

void create()
{
        set_name("Ҷѩ", ({ "ye xue", "ye", "xue" }) );
        set("gender", "Ů��");
        set("per", 30);
        set("age", 23);
        set("class", "ghost");
        create_family("����ɽׯ", 3, "����");
        set("combat_exp", 50000);
        set("long",
		"�����˾�����һ�������������ݡ��侲���пᡣ\n"
	);
        set("no_arrest",1);
        set_skill("move", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 100);
        set_skill("taiji", 50);
        set_skill("five-steps", 20);
	map_skill("dodge", "five-steps");
	map_skill("move", "five-steps");
	map_skill("unarmed", "taiji");
        setup();
	carry_object(__DIR__"obj/cloth2")->wear();
}

int accept_object(object who, object ob)
{
	object		book;

        if((string)ob->name() != "�׽�") return 0;
	command("say ��л��λ" + RANK_D->query_respect(who) + 
		"���ұ��İ׽������ҡ��Ȿ�������¡�");
	book = new(__DIR__"obj/book2");
	book->move(this_object());
	command("give book to " + who->query("id"));
        return 1;
}

