inherit NPC;

void create()
{
        set_name("道士", ({ "taoist" }) );
        set("gender", "男性");
        set("long",
		"武当派弟子，着一身灰色的道袍\n"
	);
        set("combat_exp", random(20000));
        set("score", 200);
        set("class", "taoist");
        set("force", random(300));
        set("max_force", random(300));

        create_family("武当派", 58, "弟子");

        set_skill("move", 10+random(80));
        set_skill("force", 10+random(80));
        set_skill("unarmed", 10+random(80));
        set_skill("sword", 10+random(80));
        set_skill("parry", 10+random(80));
        set_skill("dodge", 10+random(80));
        set_skill("taijiforce", 10+random(50));
        set_skill("taiji", 10+random(50));
        set_skill("three-sword", 10+random(50));
        set_skill("five-steps", 10+random(50));

        map_skill("force", "taijiforce");
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");

        set_skill("changelaw", 60);
        setup();

        add_money("silver", 5);
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/cloth")->wear();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="武当派" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 武当派不和别派的人过招。");
        return 0;
}
 
