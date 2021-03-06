// banker.c

#include <ansi.h>

inherit NPC;
inherit F_BANKOWNER;

void create()
{
        set_name("南宫十一郎", ({ "shiyi" }) );
        set("title", RED "钱庄大少" NOR);
        set("gender", "男性" );
        set("age", 22);
        set("richness",50000000);
        set("no_arrest",1);
        set("long",
                
                "中原南宫世家，家财万贯，产业不可胜数，南宫十一郎乃钱庄大少\n");

        set("combat_exp", 1000000);
        set("attitude", "friendly");
	  set_temp("kf_tufei",2);
        set("pursuer", 1);

        set("max_atman", 1000);         set("atman", 1000);             
set("atman_factor", 3);
        set("max_force", 1000);         set("force", 1000);             
set("force_factor", 3);
        set("max_mana", 1000);          set("mana", 1000);              
set("mana_factor", 3);

        set("chat_chance", 3 );
        set("chat_msg", ({
                (: exert_function, "powerfade" :),
        }) );

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("celestrike", 100);
        set_skill("celestial", 100);
        set_skill("chaos-steps", 100);

        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");
        map_skill("dodge", "chaos-steps");
        
        set("inquiry", ([
                "抢劫" : "唉！这群山西匪真厉害！来无影，去无踪！\n",
                "rob" : "唉！这群山西匪真厉害！来无影，去无踪！\n",
        ]) );

        setup();
        
        carry_object(__DIR__"obj/jinzhuang")->wear();

     }

void init()
{
        ::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
        add_action("do_loan","loan");
}

