// /d/wiz/llx/npc/npc.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIR"蒙面护卫"NOR, ({ "rguard",}) );
        set("title", RED"巫师组保镖统领"NOR);
        set("gender", "男性");
        set("age", 34);
        set("long",
"红衣，红靴，红发，红蒙面，不知道他的武功有多高．．\n"
               ); 
        set("class", "guardman");
        set("attitude", "peaceful");
        set("combat_exp", 10000000);
        set("agi",25);
        set("int",40);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sharenruma" :),
                "蒙面护卫嘴角挂着的一丝冷笑让你感到一丝恐惧，你的手脚都感觉不到温度了……\n"
        }) );
        set("int", 50);
        set("cor", 50);
        set("con", 50);
        set("str", 80);
        set("cps", 50);
        set("agi",45);
        set("int",40);
        set("force", 4000);
        set("max_force", 2200);
        set("max_kee",100000);
        set("max_gin",100000);
        set("max_sen",100000);
        set("force_factor", 300);
        set_temp("apply/damage",500);

        set_skill("sword", 10);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("literate", 100);
        set_skill("dodge", 200);
        set_skill("sharen-sword", 100);
        map_skill("sword", "sharen-sword");
        setup();
        
        carry_object("/d/kaifengfu/npc/obj/duosword")->wield();
}

void init()
{        
        object ob, me;
        object *inv;    
        int i;
        if( interactive(ob = this_player()) ) {
                me = this_player();
                if( userp(me) && me->query_temp("llx_marks/偷书")){      
                message_vision("$N冷笑道：你胆子真不小啊……\n",this_object());
                kill_ob(ob);
                return;
                }
        }
        remove_call_out("leave");
        call_out("leave",1);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "蒙面人哼了一声，化为一道虚影不见了……\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",10);
}

void killed_enemy(object who)
{
        command("say 狂妄之徒，死不足惜！\n");
        message_vision(HIR "蒙面人闭上眼睛，化为一道虚影不见了……\n" NOR,this_object());
        destruct(this_object());
}
