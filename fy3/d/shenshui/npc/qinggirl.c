// thousand_hand.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("����С��" , ({ "girl", "qing yi" }) );
	set("long", "һλʮ�����Ѿͷ������æµ�š�\n");
	set("attitude", "friendly");
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 15);
        set("gender", "Ů��" );
	set("combat_exp", 5000);
	set_skill("dodge", 50+random(100));
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}
