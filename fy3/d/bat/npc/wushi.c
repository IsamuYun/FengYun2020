// zhao.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name(HIC"青衣武士"NOR, ({ "wu shi" }) );
	set("gender", "男性" );
    set("reward_npc", 1);
    set("difficulty", 20); 

	set("long",
	"这是位蝙蝠岛岛主座前青衣武士，身披钢甲，手执长剑，双目精光炯炯，
警惕地巡视着四周的情形。\n");

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

