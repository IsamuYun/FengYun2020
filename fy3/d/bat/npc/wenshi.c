// zhao.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("������ʿ", ({ "wenshi" }) );
	set("gender", "����" );
	set("age", 42);
	
	set("long",
		"��λ������ʿ����Ǳ��������ʲô��˿��ûע�����˽�����\n");

	set("combat_exp", 350);
	set("attitude", "friendly");
	
	set("kar",15);
	set("cps",20);
	
	setup();
	carry_object("/obj/cloth")->wear();
    

}

