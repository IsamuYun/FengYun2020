// zhao.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name(HIC"������ʿ"NOR, ({ "wu shi" }) );
	set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 20); 

	set("long",
	"����λ���𵺵�����ǰ������ʿ�������ּף���ִ������˫Ŀ���⾼����
�����Ѳ�������ܵ����Ρ�\n");

	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("cor",10);
	set("spi",15);
	set("cps",10);
	set("str",50);
	set_skill("dodge",100);
    set_skill("unarmed",150);
    set_skill("parry",100);
    set_skill("sword",100);
    

	setup();
	carry_object(__DIR__"obj/gangjia")->wear();
       carry_object("/obj/weapon/sword")->wield();
    

}

