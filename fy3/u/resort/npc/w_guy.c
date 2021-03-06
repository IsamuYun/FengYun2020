
inherit NPC;

void create()
{
        set_name("黑袍公", ({ "oldguy" }) );
        set("gender", "男性" );
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("age", 65);
        set("str", 46);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);

        set("attitude", "peaceful");

        set("max_atman", 3000);
        set("atman", 3000);
        set("max_force", 300000);
        set("force", 300000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("force_factor", 50);


        set("long",     "黑袍公除了下棋，什么也不做\n");


        set("combat_exp", 999999);

        set_skill("unarmed", 100);
        set_skill("throwing", 250);
	set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);

        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 91);
        set_skill("fall-steps", 10);

        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");

        setup();

        carry_object(__DIR__"obj/wqi")->wield();
        carry_object(__DIR__"obj/bcloth")->wear();
}

 
