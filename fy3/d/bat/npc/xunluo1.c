inherit NPC;
void create()
{
        set_name("侍卫统领", ({ "shiwei"}) );
        set("gender", "男性");
        set("age", 37);
        set("long",
"这是一位蝙蝠岛专门担任巡逻之责的侍卫统领。\n"
               ); 

        set("attitude", "aggressive");

	set("cor", 30);
	set("str", 74);

	set("max_atman", 100);
	set("max_mana", 100);
	set("atman", 100);
	set("mana", 100);

        set("combat_exp", 800000+random(100000));

	set("chat_chance", 85);
        set("chat_msg", ({
		(: random_move :),
        }) );

        set_skill("bat-blade", 100+random(100));
        set_skill("dodge", 100+random(100));
        set_skill("blade", 100+random(100));
        set_skill("parry", 100+random(100));
	set_skill("move", 100+random(100));

        setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/xueblade")->wield();
}