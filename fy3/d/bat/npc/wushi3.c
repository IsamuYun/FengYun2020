
inherit NPC;

#include <ansi.h>
void create()
{
	set_name(HIW"东海白衣人"NOR, ({ "white cloth man" }) );
	set("title",HIC"一剑震神州"NOR);
    set("reward_npc", 1);
    set("difficulty", 100); 

       set("gender", "男性" );
	set("long",
	"不祥。\n");

	set("combat_exp", 10000000);
	set("attitude", "friendly");
	set("cor",10);
	set("spi",15);
	set("cps",10);
	set("str",150);
	set_skill("dodge",100);
    set_skill("unarmed",250);
    set_skill("parry",100);
    set_skill("sword",100);
    
    set_skill("kongshoudao", 110);   
    map_skill("unarmed", "kongshoudao");
    
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yaozhan" :),
        }) );

	setup();
	carry_object("/obj/cloth")->wear();
//       carry_object("/obj/weapon/sword")->wield();
    

}

