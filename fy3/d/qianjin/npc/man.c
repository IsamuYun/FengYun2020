
inherit NPC;

void create()
{
        set_name("男人" ,({ "man"}) );
        set("gender", "男性" );
        set("agi", 62);
set("str",1);
        set("long", "这是一个男人。");
        set("combat_exp", 10000000);
        set("sen",1000);
set("eff_sen",1000);
set("max_sen",1000);
set("attitude", "friendly");
        set_skill("move", 590);
	set_skill("dodge", 200);
        set("chat_chance_combat", 10);
set("chat_chance", 1);
        set("chat_msg", ({
                "男人道：天下第一．．．\n",
        }) );
	
	setup();
	
}

