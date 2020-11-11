// zhao.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("王天寿", ({ "wang tian shou" }) );
	set("gender", "男性" );
    set("reward_npc", 1);
    set("difficulty", 40); 

	set("age", 52);
	set("title",HIR"九现云龙" NOR);

	set("long",
		"这老人的一双手又黄又瘦，有如枯木，正是淮西鹰爪门的第一高手。二十 
年前已将掌门之位传给了他的侄子王维杰，近年来已很少在江湖走动。 \n");

	set("combat_exp", 800000);
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

