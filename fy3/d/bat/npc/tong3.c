// tong1.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("小书童", ({ "small kid" }) );
	set("gender", "男性" );
	set("age", 12);
	set("long",
		"这是一个可爱的小书童。\n");

	set("combat_exp", 150000);
	set("attitude", "friendly");
	set("str",20);
	set("cor",20);
	set("tol",20);
	set("agi",20);
	
	set_skill("dodge",150+random(50));
    set_skill("unarmed",150+random(50));
    set_skill("parry",300+random(10));
    set_skill("move",150+random(50));   
    

	setup();
	carry_object("/obj/cloth")->wear();
    

}

