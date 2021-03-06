//#include <ansi.h>
inherit NPC;
void create()
{
        set_name("红衣武士", ({ "wu shi"}) );
        set("gender", "男性");
        set("age", 35);
        set("long",
"这是位蝙蝠岛岛主座前红衣武士，身披钢甲，手执长剑，双目精光炯炯，
警惕地巡视着四周的情形。\n"
               ); 

        set("attitude", "heroism");

        set("str", 90);
        set("int", 90);
        set("agi", 90);
        set("con", 90);

        set("max_gin", 1100);
        set("max_kee", 1100);
        set("max_sen", 1029);
        set("eff_gin", 1100);
        set("eff_kee", 1100);
        set("eff_sen", 1029);
        set("gin", 1100);
        set("kee", 1100);
        set("sen", 1029);

        set("force", 1100);
        set("max_force", 900);
        set("force_factor", 40);

        set("combat_exp", 2500000);

        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("sword", 200);
        set_skill("parry", 200);
	set_skill("move", 200);

        setup();
	carry_object(__DIR__"obj/sword")->wield();
	carry_object(__DIR__"obj/gangjia")->wear();
}
