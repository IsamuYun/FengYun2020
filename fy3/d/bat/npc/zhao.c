// zhao.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("赵刚", ({ "zhao" }) );
	set("gender", "男性" );
    set("reward_npc", 1);
    set("difficulty", 50); 

	set("age", 42);
	set("title",HIY "单掌开碑" NOR);
	set("long",
		"大名府单掌开碑赵刚，武功之强，已可算是江湖中的一流高手,
尤擅硬功中最强的大摔碑手。\n");

	set("combat_exp", 9000000);
	set("attitude", "friendly");
	set("cor",10);
	set("spi",15);
	set("cps",10);
	set("str",50);
	set_skill("dodge",100);
    set_skill("unarmed",150);
    set_skill("parry",100);

	setup();
	carry_object("/obj/cloth")->wear();
    

}

