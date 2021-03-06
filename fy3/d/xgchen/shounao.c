// shounao.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("印尼暴徒首脑", ({ "shou nao", "nao", "shou" }) );
        set("long","这是一名印尼暴徒的幕后主持人，他手上沾满鲜血。\n");

        set("attitude", "heroism");

        set("str", 20 + random(11));            // 膂力         
        set("cps", 20 + random(11));            // 定力
        set("cor", 20 + random(11));            // 胆识         
        set("per", 20 + random(11));            // 容貌
        set("int", 20 + random(11));            // 悟性         
        set("con", 20 + random(11));            // 根骨
        set("spi", 20 + random(11));            // 灵性         
        set("kar", 20 + random(11));            // 福缘
/*
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
        }) );
*/
        set("force", 3000);      set("max_force", 3000);          set("force_factor", 10);
        set("SEN", - 50 - random( 500 ) );

        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 40);
        set_temp("apply/move", 40);

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();

        add_money("silver", 50);
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
        int n;

        if( !ob || !present(ob, environment(this_object())) ) {
                if(ob == query_leader() )  set_leader(0);
                return;
        }

        // 自动生成武功参数

        n = ob->query("combat_exp") + random(10000) - 7000;
        if( n <= 0 ) n = random(3000) + 1;

        // 降低武功
        n = n / 2;
        n = n + random(n) + 1;

        set("combat_exp", n );

        n = ob->query_skill("force", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("force", n );
        n = ob->query_skill("unarmed", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("unarmed", n );
        n = ob->query_skill("force", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("blade", n );                 // 本来的做法是取兵器中最强的一项，为了简单，这里用force取代
        n = ob->query_skill("parry", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("parry", n );
        n = ob->query_skill("dodge", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("dodge", n );
        set_skill("move", 100 + random(100) );  // 这里设置move不跟玩家的数值

        n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("hunyuan-force", n );
        n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("ruyi-blade", n );
        n = ob->query_skill(ob->query_skill_mapped("dodge"), 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("taxue-steps", n );

        map_skill("dodge", "taxue-steps");
        map_skill("move",  "taxue-steps");
        map_skill("force", "hunyuan-force");
        map_skill("blade", "ruyi-blade");
        map_skill("parry", "ruyi-blade");

        command("say " + ob->name() + "，兄弟们，给我砍了这些中国人。\n");
        set_leader(ob);

        command("kill " + ob->query("id") );
}


