// zhao.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("������", ({ "wang tian shou" }) );
	set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 40); 

	set("age", 52);
	set("title",HIR"��������" NOR);

	set("long",
		"�����˵�һ˫���ֻ����ݣ������ľ�����ǻ���ӥצ�ŵĵ�һ���֡���ʮ 
��ǰ�ѽ�����֮λ����������ֶ����ά�ܣ��������Ѻ����ڽ����߶��� \n");

	set("combat_exp", 800000);
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

