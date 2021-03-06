// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("枯梅大师", ({ "master kumei", "master", "kumei" }) );
        set("nickname", HIW"铁仙姑"NOR);
    set("reward_npc", 1);
    set("difficulty", 20); 


        set("gender", "女性" );
        set("age", 56);
        set("int", 40);
        set("spi", 21);
        set("cor", 15);
        set("con", 20);
		set("per", 15);
		set("str", 30);
		
	    set("attitude","peaceful");
        set("max_force", 9500);
        set("force", 19000);
        set("force_factor", 30);
		set("max_gin",5000);
        set("max_kee",100000);
		set("max_sen",500);
        set("long",
"这是一个白发苍苍的老妇，一张干枯瘦削的脸上满是伤疤，耳朵缺了半个，
眼睛也少了一只，剩下的一只眼睛半开半合，开合之间，精光暴射，无论谁也
不敢逼视。她身子很瘦小，但却有种说不出来的威严，无论谁人只要瞧上她 
一眼，连说话的声音都会压低些。\n"
	);
//        set("chat_chance", 1);
//        set("chat_msg", ({
//                "原随云走到琴边，一首如行云流水般的曲子从他指间溢出。
//世间己有很久没有过如此悦耳的琴声了。\n",
//        }) );

        create_family("华山派", 16, "掌门");


        set("combat_exp", 1100000);
        set("chat_chance_combat", 80);
     set("chat_msg_combat", ({
            (: perform_action, "sword.poqi" :),
        }) );

        set_skill("move", 100);
        set_skill("parry", 90);
        set_skill("dodge", 100);
        set_skill("force", 90);
	    set_skill("unarmed", 70);
	    set_skill("wuzheng-force",200);
        set_skill("literate", 100);
	    set_skill("sword",150);
	    set_skill("dugu-sword",180);
      set_skill("meng-steps",220);
        
	    map_skill("force", "wuzheng-force");
	   map_skill("parry","dugu-sword");
        map_skill("sword","dugu-sword");
        map_skill("dodge","meng-steps");
      map_skill("move","meng-steps"); 
     	

        setup();
        carry_object("/obj/weapon/sword")->wear();
        carry_object(__DIR__"obj/cloth1")->wield();
}

/*
void attempt_apprentice(object ob)
{
//	command("smile");
	call_out("do_recruit", 1, ob);
//        command("recruit " + ob->query("id") );

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
}
void do_recruit(object ob)
{
 if( (int)ob->query_skill("sword") < 200 )
 {
  command("say 你的剑术造诣还不够高！\n");
  return;
 }
 if( (int)ob->query("PKS") > 30 )
 {
  command("say 你杀人太多了，不能收你了！\n");
  return;
 }
 command("smile");
 command("say 很好，很好，很好。");
 command("recruit " + ob->query("id") );
}
 
void re_rank(object student)
{
       
                student->set("title","华山派弟子");
                return ;

}
*/
