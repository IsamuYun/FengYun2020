inherit NPC;
void create()
{	set_name("С����",({"room master","master"}));
	set("title","���Ʒ���");
	set("gender","Ů��");
	set("age",22);
	set("combat_exp",9999999);
	set("attitude","heroism");
	setup();
	carry_object("/obj/cloth")->wear();
}
#include "master_func.c"