inherit NPC;
void create()
{	set_name("³��",({"room builder","builder"}));
	set("gender","����");
	set("age",32);
	set("combat_exp",9999999);
	set("attitude","heroism");
	setup();
	carry_object("/obj/cloth")->wear();
}
#include "build_func.c"
