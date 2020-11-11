// taolord.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("丁乘风", ({ "master ding", "master", "ding" }) );
        set("nickname", HIG"碧海乘风" NOR);
        set("gender", "男性");

    set("reward_npc", 1);
    set("difficulty", 150); 
        set("age", 47);
        set("long",
                
"丁乘风原本出身武林世家，但从小好学，擅长钻研心法，\n"
"于是隐居于此精修成仙降魔之道。\n");

        set("combat_exp", 10000000);
        set("score", 200000);

        set("class", "taoist");

        set("str", 20);
        set("int", 30);
        set("cor", 20);
        set("cps", 30);
        set("spi", 30);

        set("force", 2000);
        set("max_force", 1000);
        set("force_factor", 30);

        set("atman", 1400);
        set("max_atman", 1400);

        set("mana", 4000);
        set("max_mana", 2000);
        set("mana_factor", 5);

        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我三清宫为对抗邪魔外道所创的内功心法。\n",
                "三清宫": 
"我三清宫自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n"
        ]) );

        set("apprentice_available", 3);
        create_family("三清宫", 5, "主持");

        set_skill("literate", 70);
        set_skill("magic", 40);
        set_skill("force", 30);
        set_skill("move", 40);
        set_skill("scratching", 200);
	set_skill("spells",50);
        set_skill("unarmed", 30);
        set_skill("sword", 100);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("gouyee", 60);
	set_skill("notracesnow", 100);
	set_skill("snowshade-sword", 100);

        set_skill("taoism", 100);
        set_skill("scratmancy", 100);
	set_skill("necromancy",50);

        map_skill("scratching", "scratmancy");
        map_skill("parry", "snowshade-sword");
        map_skill("sword", "snowshade-sword");
        map_skill("move", "notracesnow");
        map_skill("dodge", "notracesnow");



        set_temp("apply/dodge", 20);
        set_temp("apply/armor", 20);
        setup();

        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/robe")->wear();
        carry_object(__DIR__"obj/hat")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
}

