// wei.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("κ����", ({ "wei xing long" }) );
    set("reward_npc", 1);
    set("difficulty", 30); 

	set("gender", "����" );
	set("age", 35);
	set("title",MAG  "����ɷ��" NOR);
	set("long",
		"�������۾���һ�����̣������������۽�һֱ�����������䳤����̫�
������������������Ѫ������ָ�������˺��ѷ����������̡�\n");

	set("combat_exp", 1000000);
	set("attitude", "friendly");
	set("per",30);
	set("force",100);
	set("max_force",100);	
	set_skill("dodge",50);
    set_skill("unarmed",250);
    set_skill("celestrike", 100);
    set_skill("chaos-steps", 100);
    map_skill("unarmed", "celestrike");
    map_skill("dodge", "chaos-steps");

	setup();
	carry_object("/obj/cloth")->wear();

}

