// xun-bu.c
// modify by zen
#include <ansi.h>
#include <login.h>

inherit NPC;

void make_skill();
void checking(object ob);

void create()
{
        int iType;

        iType = random(5);

        if(( iType == 1 ) || ( iType == 2 ))
                set_name("捕快", ({ "xun bu" }) );
        else if(( iType == 3 ) || ( iType == 4 ))
                set_name("巡捕", ({ "xun bu" }) );
        else
                set_name("捕头", ({ "xun bu" }) );


        set("long", sprintf("这是一位%s。\n", name()));

        set("attitude", "heroism");
        set("age", random(20) + 20);

        set("str", 30 + random(20));            // 膂力         
        set("cps", 30 + random(20));            // 定力
        set("cor", 30 + random(20));            // 胆识         
        set("per", 30 + random(20));            // 容貌
        set("int", 30 + random(20));            // 悟性         
        set("con", 30 + random(20));            // 根骨
        set("spi", 30 + random(20));            // 灵性         
        set("kar", 30 + random(20));            // 福缘

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
/*
                sprintf("%s喝道：今天不给点教训你，也不知道老子的厉害！\n", name()),
                sprintf("%s喝道：多管闲事，你活得不耐烦了吧！\n", name()),
                sprintf("%s喝道：呸！大爷的事也管，去死吧！\n", name()),
*/
                (: exert_function, "protect" :),
                // (: perform_action :),                // (: perform_action, "sword.counterattack" :),
                (: exert_function, "recover" :),
        }) );

        set("chat_chance", 100);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("SEN", 0);
/*
        if( iType == 0 ) {
                set_skill("force", 250 );
                set_skill("unarmed", 250 );
                set_skill("sword", 250 );
                set_skill("parry", 250 );
                set_skill("dodge", 250 );
                set_skill("move", 250 );
                set_skill("taiji-force", 250 );
                set_skill("xuantie-sword", 250 );
                set_skill("lingbo-steps", 250 );
        set("mana", 2000);      set("max_mana", 2000);
        set("atman", 2000);      set("max_atman", 2000);
        set("force", 4000);      set("max_force", 2000);  set("force_factor", 30);
        set("combat_exp", random(100) * 10000 + 5000000 );
}else 
*/
        if(( iType == 1 ) || ( iType == 2 )){
                set_skill("force", 250 );
                set_skill("unarmed", 250 );
                set_skill("sword", 250 );
                set_skill("parry", 250 );
                set_skill("dodge", 250 );
                set_skill("move", 250 );
                set_skill("taiji-force", 250 );
                set_skill("xuantie-sword", 250 );
                set_skill("lingbo-steps", 250 );
        set("max_kee",3000);    set("kee",3000);
        set("max_gin",3000);    set("gin",3000);
        set("max_sen",3000);    set("sen",3000);
        set("mana", 2000);      set("max_mana", 2000);
        set("atman", 2000);      set("max_atman", 2000);
        set("force", 4000);      set("max_force", 2000);  set("force_factor", 30);
        set("combat_exp", random(1000) * 10000 + 10000000 );
        }else if(( iType == 3 ) || ( iType == 4 )) {
                set_skill("force", 350 );
                set_skill("unarmed", 350 );
                set_skill("sword", 350 );
                set_skill("parry", 350 );
                set_skill("dodge", 350 );
                set_skill("move", 350 );
                set_skill("taiji-force", 350 );
                set_skill("xuantie-sword", 350 );
                set_skill("lingbo-steps", 350 );
        set("max_kee",5000);    set("kee",5000);
        set("max_gin",5000);    set("gin",5000);
        set("max_sen",5000);    set("sen",5000);
        set("mana", 3000);      set("max_mana", 3000);
        set("atman", 3000);      set("max_atman", 3000);
        set("force", 6000);      set("max_force", 3000);  set("force_factor", 60);
        set("combat_exp", random(1000) * 10000 + 20000000 );
        }else {
                set_skill("force", 450 );
                set_skill("unarmed", 450 );
                set_skill("sword", 450 );
                set_skill("parry", 450 );
                set_skill("dodge", 450 );
                set_skill("move", 450 );
                set_skill("taiji-force", 450 );
                set_skill("xuantie-sword", 450 );
                set_skill("lingbo-steps", 450 );
        set("max_kee",8000);    set("kee",8000);
        set("max_gin",8000);    set("gin",8000);
        set("max_sen",8000);    set("sen",8000);
        set("mana", 4000);      set("max_mana", 4000);
        set("atman", 4000);      set("max_atman", 4000);
        set("force", 10000);      set("max_force", 5000);  set("force_factor", 90);
        set("combat_exp", random(1000) * 10000 + 30000000 );
        }

        map_skill("dodge", "lingbo-steps");
        map_skill("move",  "lingbo-steps");
        map_skill("force", "taiji-force");
        map_skill("sword", "xuantie-sword");
        map_skill("parry", "xuantie-sword");

        setup();

        carry_object("/obj/cloth/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();

        add_money("gold", 1);
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checking");
                call_out("checking", 1, ob);
        }
}

void checking(object ob)
{
        object me;


        if ( !ob->query("kill_flag") ) return;
        command("say " + ob->name() + "，你杀了人，你死定了！！\n");
        set_leader(ob);

        command("kill " + ob->query("id") );
        command("exert protect");
        return;
}
