// wei.c

inherit NPC;

#include <ansi.h>
int go_dahai(object);
void create()
{
	set_name("丁枫", ({ "ding feng" }) );
    set("reward_npc", 1);
    set("difficulty", 80); 

	set("gender", "男性" );
	set("age", 24);
	set("title",HIC  "玉树临风" NOR);
	set("long",
		"这轻衫少年袍袖飘飘，不但神情很潇洒，人也长得很英俊，
脸上更永远都带着笑容。\n");
    set("chat_msg", ({
            "丁枫微笑道：“清风十三式”妙就妙在“清淡”两字,讲究的正是：似有似无，
似实似虚，似变未变 。\n",
    }) );

	set("combat_exp", 700000);
	set("attitude", "friendly");
	set("per",30);
	set("force",100);
	set("max_force",100);	
	set_skill("dodge",50);
    set_skill("unarmed",250);
    set_skill("sword",100);
set_skill("dugu-sword",240);
    set_skill("meng-steps", 100);
    map_skill("sword", "dugu-sword");
    map_skill("dodge", "meng-steps");
	        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.pocan" :),
                 (: perform_action, "sword.poqi" :),
        }) );
setup();
	carry_object("/obj/cloth")->wear();
    carry_object("obj/weapon/sword")->wield();

}

int accept_object(object who, object ob)
{
    
	object paper;

    if( ob->name()!="清风十三式" )
      return 0;
    else 
	{
      remove_call_out("go_dahai");
      call_out("go_dahai", 1, ob);

      return 1;
    }
}
go_dahai()
{
      object me,room;
      string myfile;
	  me=this_player();
      say("丁枫愉快地笑了笑。\n");
      command("say 好，看来你正是我们要找的人了，随我来！\n");
      tell_object(me,HIC"你大喜过望，得意洋洋的跟着丁枫走上了大海船.......\n");
	  tell_object(me,"船夫一见有人上船，忙叫了一声：开船喽！
船夫升起帆，船就向东方航行。\n");
      room = load_object("/d/bat/dahai");
	  if(room) me->move(room);
	  
      return 1;
}

