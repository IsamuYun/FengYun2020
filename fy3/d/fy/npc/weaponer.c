
inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("�����", ({ "zhuge" }) );
	set("gender", "����" );
	set("age", 31);
	set("title", HIG "���罣" NOR);
	set("long",
		"��ʨ�ھֵĴ���ͷ���ֵ��»����ԣ�\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
		  set_temp("kf_tufei",67);
        set("pursuer", 1);
set("per",30);
	set("vendor_goods", ([
               "/obj/weapon/whip":20,
               "/obj/weapon/longsword":20,
               "/obj/weapon/dart":10,
               "/obj/weapon/shield":10,
               "/obj/weapon/eighthammer":10,
               "/obj/weapon/thin_sword":10,
               "/obj/weapon/dagger.c":10,
               "/obj/weapon/blade.c":10,
		__DIR__"obj/1staff.c":10,
               __DIR__"obj/knife.c":20,
               __DIR__"obj/dual_ring.c":10,
	]) );
	set_skill("sword",50);
	set_skill("six-chaos-sword",50);
	set_skill("pyrobat-steps",50);
	set_skill("dodge",50);
	set_skill("parry",50);
	map_skill("dodge","pyrobat-steps");
	map_skill("parry", "six-chaos-sword");
	map_skill("sword","six-chaos-sword");
	setup();
	carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object("/obj/longsword")->wield();
}
void init()
{
        add_action("do_vendor_list", "list");
}

