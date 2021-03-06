// man.c

#include <ansi.h>
#include <login.h>

inherit NPC;

void make_skill();
void checking(object ob);

void create()
{
/*
        string *my_name = ({ "恶棍", "恶霸", "流氓" });
        string *ob_name = ({ "小男孩", "小女孩", "年轻人", "小姑娘", "姑娘", 
                             "老头子", "老太太" });
        set_name(my_name[ random( sizeof(my_name) ) ], ({ "good man" }) );
*/
        int iType;

        iType = random(2);

        if( iType == 1 ) 
                set_name("大侠", ({ "good man", "man" }) );
        else
                set_name("大魔", ({ "bad man", "man" }) );

        message("system", HIY"【" MUD_NAME "】" + query("name") + "（" + query("id") + "）："
                + ( (iType == 1) ? 
                        "独孤九剑，一剑惊人！斩魔除妖，为民除害！！" : 
                        "八荒六合，唯我独尊！斩尽大侠，一统江湖！！" )
                + "\n" NOR, users() );

        set("long", sprintf("这是一位%s。\n", name()));

        set("attitude", "heroism");
        set("age", random(20) + 20);

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
                sprintf("%s喝道：今天不给点教训你，也不知道老子的厉害！\n", name()),
                sprintf("%s喝道：多管闲事，你活得不耐烦了吧！\n", name()),
                sprintf("%s喝道：呸！大爷的事也管，去死吧！\n", name()),
        }) );
*/
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("force", 2000);      set("max_force", 2000);  set("force_factor", 10);
        set("SEN", (iType == 1) ? 500 : -500);

        set_skill("force", random(40) + 10 );
        set_skill("unarmed", random(40) + 10 );
        set_skill("parry", random(40) + 10 );
        set_skill("move", random(40) + 10 );
        set_skill("dodge", random(40) + 10 );
        set("combat_exp", random(4000) + 1000);

        make_skill();

        setup();

        carry_object("/obj/cloth/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();

        add_money("gold", 10);
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

// 自动生成武功参数
void make_skill()
{
        int i, n, t;
        object *ob, me;

        ob = users();
        me = this_object();

        if(sizeof(ob) == 0) return;
        n = 1;
        t = ob[0]->query("combat_exp");
        i = sizeof(ob);
        while(i--)
        	if( !ob[i])continue;//add bye zen try to keep from crah
                else if( t < ob[i]->query("combat_exp") ) {
                        n = i;
                        t = ob[i]->query("combat_exp");
                }

        t = n;
        n = ob[t]->query("combat_exp") + random(1000000);
        if( n <= 0 ) n = random(10000) + 1;
        set("combat_exp", n );

        n = ob[t]->query_skill("force", 1) + random(50) + 1;
        if( n <= 0 ) n = random(50) + 1;
        set_skill("force", n );
        n = ob[t]->query_skill("unarmed", 1) + random(50) + 1;
        if( n <= 0 ) n = random(50) + 1;
        set_skill("unarmed", n );
        n = ob[t]->query_skill("force", 1) + random(50) + 1;
        if( n <= 0 ) n = random(50) + 1;
        set_skill("blade", n );                 // 本来的做法是取兵器中最强的一项，为了简单，这里用force取代
        n = ob[t]->query_skill("parry", 1) + random(50) + 1;
        if( n <= 0 ) n = random(50) + 1;
        set_skill("parry", n );
        n = ob[t]->query_skill("dodge", 1) + random(50) + 1;
        if( n <= 0 ) n = random(50) + 1;
        set_skill("dodge", n );
        set_skill("move", 100 + random(100) );  // 这里设置move不跟玩家的数值

        n = ob[t]->query_skill(ob[t]->query_skill_mapped("force"), 1) + random(50) + 1;
        if( n <= 0 ) n = random(50) + 1;
        set_skill("hunyuan-force", n );
        n = ob[t]->query_skill(ob[t]->query_skill_mapped("force"), 1) + random(50) + 1;
        if( n <= 0 ) n = random(50) + 1;
        set_skill("ruyi-blade", n );
        n = ob[t]->query_skill(ob[t]->query_skill_mapped("dodge"), 1) + random(50) + 1;
        if( n <= 0 ) n = random(50) + 1;
        set_skill("taxue-steps", n );

        map_skill("dodge", "taxue-steps");
        map_skill("move",  "taxue-steps");
        map_skill("force", "hunyuan-force");
        map_skill("blade", "ruyi-blade");
        map_skill("parry", "ruyi-blade");
}

void checking(object ob)
{
        object me;
        // command("say " + ob->name() + "，你死定了！！\n");
        // set_leader(ob);

        me = this_object();

        if( ob->query("combat_exp") < 15000 ) return;
        
        if( ( me->query("SEN") < 0 && ob->query("SEN") > 0 )
        || ( me->query("SEN") > 0 && ob->query("SEN") < 0 ))
                command("kill " + ob->query("id") );
        return;
}
