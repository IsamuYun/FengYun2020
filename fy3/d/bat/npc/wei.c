// wei.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("魏行龙", ({ "wei xing long" }) );
    set("reward_npc", 1);
    set("difficulty", 30); 

	set("gender", "男性" );
	set("age", 35);
	set("title",MAG  "紫面煞神" NOR);
	set("long",
		"此人左眼睛有一条刀疤，这条刀疤自眼角一直划到耳根，虽长而不太深，
而且天生异像，面如紫血，若不指明，别人很难发现这条刀疤。\n");

	set("combat_exp", 1000000);
	set("attitude", "friendly");
	set("per",30);
	set("force",100);
	set("max_force",100);	
	set_skill("dodge",50);
    set_skill("unarmed",250);
    set_skill("celestrike", 100);
    set_skill("chaos-steps", 100);
    map_skill("unarmed", "celestrike");
    map_skill("dodge", "chaos-steps");

	setup();
	carry_object("/obj/cloth")->wear();

}

