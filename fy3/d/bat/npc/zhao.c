// zhao.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("�Ը�", ({ "zhao" }) );
	set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 50); 

	set("age", 42);
	set("title",HIY "���ƿ���" NOR);
	set("long",
		"���������ƿ����Ըգ��书֮ǿ���ѿ����ǽ����е�һ������,
����Ӳ������ǿ�Ĵ�ˤ���֡�\n");

	set("combat_exp", 9000000);
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

