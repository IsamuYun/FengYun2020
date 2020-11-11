inherit NPC;
void create()
{	set_name("Â³°à",({"room builder","builder"}));
	set("gender","ÄÐÐÔ");
	set("age",32);
	set("combat_exp",9999999);
	set("attitude","heroism");
	setup();
	carry_object("/obj/cloth")->wear();
}
#include "build_func.c"
