inherit NPC;
#include <ansi.h>
void create()
{
        set_name("达摩", ({ "master damo", "master","damo"}) );
        set("vendetta_mark","shaolin");
        set("gender", "男性" );
        set("title", "少林始祖" );
    set("reward_npc", 1);
    set("difficulty", 300); 

        set("age", 150);
        set("agi",30);
        set("per", 35);
        set("int",200);
        set("str",500);
        set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("long",
"少林始祖！\n"
        );
        create_family("少林寺", 1, "始祖");
        set("combat_exp", 130000000);
        set_temp("apply/damage",2000);
        set_skill("move", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("axe", 200);
        set_skill("dagger", 200);
        set_skill("iron-cloth", 200);
        set_skill("perception", 200);
        set_skill("throwing", 200);
        set_skill("herb", 200);
        set_skill("spear", 200);
        set_skill("literate", 220);
        set_skill("unarmed",200);
        set_skill("puti-steps",200);
        set_skill("dabei-strike",200);
        set_skill("buddhism",200);
        set_skill("chanting",200);
        set_skill("xiaochengforce",200);
        set_skill("staff",200);
        set_skill("parry",200);
        set_skill("fumostaff",200);
        set_skill("blade",200);
        set_skill("sword",200);
        set_skill("damo-sword",200);
        set_skill("whip",200);
        set_skill("tianlongwhip",200);
        set_skill("suiyuan-sword",200);
        set_skill("lianxin-blade",200);
        set_skill("xingyi-stick",200);
        set_skill("dachengforce", 200);
        set_skill("liuxing-hammer", 200);
        set_skill("hammer", 200);
        set_skill("wuche-axe", 200);
        set_skill("duanhun-spear", 200);
        set_skill("yiyangzhi", 200);
        set_skill("yijinjing", 200);
       map_skill("sword","suiyuan-sword");
        map_skill("staff","xingyi-stick");
        map_skill("parry","lianxin-blade");
        map_skill("dodge", "puti-steps");
        map_skill("force", "yijinjing");
        map_skill("unarmed", "dabei-strike");
        map_skill("blade","lianxin-blade");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
}
void attempt_apprentice(object ob)
{
        if(ob->query("class")!="shaolin")
        {
                 message_vision("$N笑道：你何来就从何去．．．\n",
        this_object());
        return;
        }
        if((int) ob->query("force_factor") < 100)
        {
         message_vision("$N笑道：武功的太差了．．．\n",
        this_object());
        return;
        }
    if ( random(250) || random((int)ob->query("kar")) <  25 )
        {
        message_vision("$N说道：我是已去之人............\n",
        this_object());
                return;
        }
         if ( !ob->query("m_success/勇保经书"))
        {
        message_vision("$N咳了两声，说道：你有为少林做过事情吗？\n",
        this_object());
                return;
               }
        if(!ob->query_temp("won_master_yi"))    
                {
        message_vision("$N说道：你是的佛理还不怎么懂呢？\n",
        this_object());
                return;
        }
         if(!ob->query("juexue"))        
                {
        message_vision("$N说道：哎．．．．．．．．．．\n",
        this_object());
                return;
        }
      command("sigh");
        command("say 很好，" + RANK_D->query_respect(ob) + 
"既然我们有缘，老衲就收你为徒，希望你振兴少林。\n");
        command("recruit " + ob->query("id") );
    }
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
}
void re_rank(object student)
{
                student->set("title","少林寺护寺长老");
                return ;
}
int is_ghost() { return 1; }
