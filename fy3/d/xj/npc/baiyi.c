#include <ansi.h>
inherit NPC;

void create()
{
        set_name("白衣人", ({ "man in white" }) );
        set("gender", "男性");
        set("age", 37);
        set("long","他看起来就象是二十年前就已经名动江湖的＂一剑飞花＂花满天，他
现在却站在这里一动不动！\n"); 
        set("title",HIW"一动不动"NOR);
        set("combat_exp", 10000000);
	set("bellicosity" , 20);
	set("PKS" , 1);
        set_skill("sword", 150);
        set_skill("dodge", 100);
        set_skill("feixian-steps", 100);
        set_skill("feixian-sword", 120);
	set_skill("move", 50);
        map_skill("dodge", "feixian-steps");
        map_skill("move", "feixian-steps");
        map_skill("sword", "feixian-sword");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
		(: perform_action,       "sword.tianwaifeixian" :),
		(: perform_action,       "dodge.tianwaifeixian" :)
        }) );
        setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}
