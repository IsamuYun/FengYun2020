#include <ansi.h>

inherit NPC;

void create()
{
        set_name("无名", ({  "wu ming" }));
        set("long",
            "他就是「捕头联盟」的一级捕头.\n"+
            "他面色煞白,你不敢多看了一眼.\n");
        set("title", HIR"御前神捕"NOR);
        set("gender", "男性");
        set("age", 36);
        set("shen_type",0);
        set("attitude", "peaceful");

     set("str", 500);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
         set("kee", 5000000);
        set("max_kee", 5000000);
       set("sen", 5000000);
        set("max_sen", 5000000);
        set("gin", 1400000);
    set("max_gin", 500000);
      set("force", 90000000);
    set("max_force", 2000000);

     set("combat_exp", 60000000);
        set("score", 2000000);
        set_skill("force", 500);
        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("parry", 550);
        set_skill("sword",550);
        set_skill("literate", 200);
        set_skill("move", 500);
        set_skill("feixian-steps", 500);
        set_skill("yiqiguanforce", 500);
        set_skill("iron-cloth",500);

        map_skill("force", "yiqiguanforce");
        map_skill("unarmed", "yiqiguanforce");
        map_skill("move", "feixian-steps");
        map_skill("dodge", "feixian-steps");

set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: random_move :),
                (: perform_action, "unarmed.yiqiguanriyue" :),
                        }) );
        setup();
    carry_object("/obj/cloth")->wear();
       
}

void init()
{
        object ob;

        ::init();

        ob = this_player();

        if (ob->query("OPK") > 2 )
        {
                     ob->set("OPK",0);
                        command("heng");
                        command("say \n你已经杀了超过两个人了。\n我平生最讨厌你这些喜欢杀人的人！跟我回去！\n");
                         ob->set("qiushi/howlong",60);
                          ob->move("d/wiz/qiushi");
        remove_call_out("leave");
  call_out("leave",100);
        }
}
void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "无名大摇大摆得走了！\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",10);
}


