// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("原随云", ({ "master yuan", "master", "yuan" }) );
        set("nickname", HIR"蝙蝠公子"NOR);

        set("gender", "男性" );
        set("reward_npc", 1);
        set("difficulty", 150); 

        set("age", 26);
        set("int", 40);
        set("spi", 21);
        set("cor", 15);
        set("con", 20);
		set("per", 40);
		set("str", 30);
		
	    set("attitude","peaceful");
        set("max_force", 9500);
        set("force", 19000);
        set("force_factor", 100);
		set("max_gin",5000);
        set("max_kee",100000);
		set("max_sen",500);
        set("long",
"他笑容温柔而亲切，但一双眼睛里，却带着种说不出的空虚、寂寞、萧索
之意, 是个很秀气，很斯文的少年，穿着虽华丽，但却不过火。\n"
	);
        set("chat_chance", 1);
        set("chat_msg", ({
                "原随云走到琴边，一首如行云流水般的曲子从他指间溢出。
世间己有很久没有过如此悦耳的琴声了。\n",
        }) );

        create_family("无争山庄", 1, "少庄主");


        set("combat_exp", 80000000);
        set("chat_chance_combat", 80);
     set("chat_msg_combat", ({
            (: perform_action, "blade.shiwanshenmo" :),
        }) );

        set_skill("move", 100);
        set_skill("parry", 90);
        set_skill("dodge", 100);
        set_skill("force", 90);
	    set_skill("unarmed", 70);
	    set_skill("wuzheng-force",220);
        set_skill("literate", 150);
	    set_skill("blade",150);
	    set_skill("bat-blade",150);
      set_skill("meng-steps",220);
        
	    map_skill("force", "wuzheng-force");
	   map_skill("parry","bat-blade");
        map_skill("blade","bat-blade");
        map_skill("dodge","meng-steps");
      map_skill("move","meng-steps"); 
     	

        setup();
        carry_object(__DIR__"obj/ruanjia")->wear();
        carry_object(__DIR__"obj/yunblade")->wield();
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
                ob->set("class", "wuzheng");
}
void do_recruit(object ob)
{
 if( (int)ob->query_cor() < 30 )
 {
  command("say 我从不收胆小之人，您请回吧！\n");
  return;
 }
 if( (int)ob->query_skill("force",1) < 150 )
 {
  command("say 原随云说道：你的内功太差了,还是努努力先提高一下吧!\n");
  return;
 }
 if(ob->query("marks/killed_hu")!=1)
 {
  command("say 原随云说道：你听没听过借刀杀人这句话 ？我现在想借阁下的刀。。。\n");
  return;
 }
//原随云说道：你听没听过借刀杀人这句话 ？我现在想借阁下的刀。。。

 command("smile");
 command("say 很好，很好，很好。");
 command("recruit " + ob->query("id") );
}
 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","蝙蝠岛弟子");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","蝙蝠岛弟子");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","蝙蝠岛弟子");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","蝙蝠岛玄武神");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","蝙蝠岛玄武神");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","蝙蝠岛朱雀神");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","蝙蝠岛朱雀神");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","蝙蝠岛白虎神");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","蝙蝠岛白虎神");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","蝙蝠岛青龙神");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","蝙蝠岛青龙神");
                return ;
        } else
                student->set("title","无争山庄副庄主");
                return ;

}

*/