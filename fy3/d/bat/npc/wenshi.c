// zhao.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("中年文士", ({ "wenshi" }) );
	set("gender", "男性" );
	set("age", 42);
	
	set("long",
		"这位中年文士正在潜心钻研着什么，丝毫没注意有人进来。\n");

	set("combat_exp", 350);
	set("attitude", "friendly");
	
	set("kar",15);
	set("cps",20);
	
	setup();
	carry_object("/obj/cloth")->wear();
    

}

