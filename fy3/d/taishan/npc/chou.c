#include <ansi.h>
inherit NPC;
int wieldblade();
void create()
{
        set_name("仇二先生", ({ "mr er" }) );
        set("gender", "男性");
    set("reward_npc", 1);
    set("difficulty", 40); 

	set("age",35);
        set("combat_exp", 1000000);
        set("long",
		"道装玄冠，长身玉立，背负长剑，苍白的脸上眼角上挑，带着种说不出的傲气，
两条几乎连接在一起的浓眉间，又仿佛充满了仇恨。\n"
	);
	set("max_force",3000);
	set("force",3000);
	set("force_factor",30);
	set_skill("move",100);
        set_skill("parry", 250);
	set_skill("sword",250);
	set_skill("dodge",1);
	set_skill("feixian-steps",150);
	map_skill("dodge","feixian-steps");
	set_skill("feixian-sword",100);
	map_skill("sword","feixian-sword");
	map_skill("parry","feixian-sword");
        set("chat_chance", 15);
        set("chat_msg", ({
	(: random_move :),
       (: random_move :),
        (: random_move :),
     (: random_move :),
        }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: wieldblade  :),
        }) );
        setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword");
}
int wieldblade()
{
command("wield sword");
perform_action("dodge.tianwaifeixian");
command("unwield sword");
return 1;
}
