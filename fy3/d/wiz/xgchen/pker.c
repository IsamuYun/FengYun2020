#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({  "wu ming" }));
        set("long",
            "�����ǡ���ͷ���ˡ���һ����ͷ.\n"+
            "����ɫɷ��,�㲻�Ҷ࿴��һ��.\n");
        set("title", HIR"��ǰ��"NOR);
        set("gender", "����");
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
                        command("say \n���Ѿ�ɱ�˳����������ˡ�\n��ƽ������������Щϲ��ɱ�˵��ˣ����һ�ȥ��\n");
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
                message_vision(HIC "������ҡ��ڵ����ˣ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",10);
}


