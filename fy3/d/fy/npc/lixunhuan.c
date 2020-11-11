// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>
void create()
{
        set_name("李寻欢", ({ "master li", "master", "master li xunhuan" }) );
        set("nickname", RED"小李飞刀"NOR);
        set("gender", "男性" );
    set("reward_npc", 1);
    set("difficulty", 250); 
        set("age", 44);
        set("str", 80);
        set("cor", 80);
        set("cps", 80);
        set("agi", 80);
        set("int", 30);
        set("dur", 400);
        set("per", 30);
        set("class", "traveller");
        set("attitude","friendly");
        set("max_force", 15000);
        set("force", 150000000);
        set("courage",1000);
        set("force_factor", 420);

        set("rank_info/respect", "李探花");

        set("long",
"李寻欢别号李探花，又有江湖绰号小李飞刀。
一手飞刀绝技，在百晓生的兵器谱上排行第三。
不发则已，但例无虚发。\n"                
        );
        create_family("风云一刀", 2, "人杰");
        set("student_title","人杰");
        set("combat_exp", 50000000);
        set("score", 200000);

        set("chat_chance", 10);
        set("chat_msg", ({
                "李寻欢仍然一口一口的喝着桂花酒。\n",
                "李寻欢不停的在咳，嘴角流下一丝鲜血。\n",
                "李寻欢的脸色越发苍白了。\n",
"李寻欢叹口气，呆呆地望着手里的木像。\n",
        }) );
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
        set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);
        map_skill("throwing", "feidao");
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
                carry_object(__DIR__"obj/guihua");
}

void attempt_apprentice(object ob)
{
        if(time()-(int) ob->query("last_time_app_master_li") < 899)
        {
                 message_vision("$N笑道：你怎么这么快又回来了．．．\n",
        this_object());
        return;
        }
        if((int) ob->query("force_factor") < 100)
        {
         message_vision("$N笑道：你对武功的了解还不够．．．\n",
        this_object());
        return;

        }
        if( random(500) || random((int)ob->query("kar")) <  25 || query("already") || ob->query("baixiaoli"))
        {
        message_vision("$N咳了两声，说道：不要开玩笑，我可不想误人子弟。\n",
        this_object());
        ob->set("last_time_app_master_li",time());
                return;
        }

        command("sigh");
        command("say 很好，" + RANK_D->query_respect(ob) + 
"他日切不可为非作歹。\n");
        command("recruit " + ob->query("id") );
        ob->delete("betrayer");
        ob->add("score",5000);
        ob->add("baixiaoli",1);
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "traveller");
        set("already",1);
}
void reset()
{
        set("already",0);
} 

object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

void heart_beat()
{
        object feidao;
        object target;
        if(!query_temp("weapon") && is_fighting())
        {
                target = offensive_target(this_object());
            if(objectp(target))
            {
                target->receive_damage("kee",1000,this_object());
                        feidao = new(__DIR__"obj/xlfd_knife");
                        feidao->move(this_object());
                        command("wield flying blade");
                (CLASS_D("traveller") + "/feidao/xiaoli-feidao")->kill_him(this_object(),target);
                        WEAPON_D->throw_weapon(this_object(),target,feidao,0);
                }
                return;
        }
        else
   return ::heart_beat();  
}

void init()
{
    add_action("do_kill", "kill");
}

int do_kill(string arg)
{
        object feidao;
    object me;
    
    if(!arg)
    {
        return 0;       
    }
    
    if(strsrch(arg, "master") == -1)
    {
        return 0;       
    }
        
    me = this_player();
    message_vision("\n$N对著李寻欢喝道：「老匹夫！今日不是你死就是我亡！」\n\n",me);

    this_object()->kill_ob(me);
    me->kill_ob(this_object());    
        if(objectp(me))
        {
                me->receive_damage("kee",1000,this_object());
                        feidao = new(__DIR__"obj/xlfd_knife");
                        feidao->move(this_object());
                        command("wield flying blade");
                (CLASS_D("traveller") + "/feidao/xiaoli-feidao")->kill_him(this_object(),me);
                        WEAPON_D->throw_weapon(this_object(),me,feidao,0);
        }
    return 1;
}

