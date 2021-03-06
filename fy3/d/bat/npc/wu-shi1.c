//#include <ansi.h>
inherit NPC;
void create()
{
        set_name("白衣武士", ({ "wu shi"}) );
        set("gender", "男性");
        set("age", 35);
        set("long",
"这是位蝙蝠岛岛主座前白衣武士，身披钢甲，手执长剑，双目精光炯炯，
警惕地巡视着四周的情形。\n"
               ); 

        set("attitude", "heroism");

        set("str", 120);
        set("int", 120);
        set("agi", 120);
        set("con", 120);

        set("max_gin", 1200);
        set("max_kee", 1200);
        set("max_sen", 1326);
        set("eff_gin", 1200);
        set("eff_kee", 1200);
        set("eff_sen", 1326);
        set("gin", 1200);
        set("kee", 1200);
        set("sen", 1326);

        set("force", 1200);
        set("max_force", 1000);
        set("force_factor", 50);

        set("combat_exp", 3500000);

        set_skill("unarmed", 220);
        set_skill("dodge", 220);
        set_skill("sword", 220);
        set_skill("parry", 220);
	set_skill("move", 220);

        setup();
	carry_object(__DIR__"obj/sword")->wield();
	carry_object(__DIR__"obj/gangjia")->wear();
}
