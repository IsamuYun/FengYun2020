inherit NPC;
void create()
{	set_name("小苗苗",({"room master","master"}));
	set("title","风云房管");
	set("gender","女性");
	set("age",22);
	set("combat_exp",9999999);
	set("attitude","heroism");
	setup();
	carry_object("/obj/cloth")->wear();
}
#include "master_func.c"