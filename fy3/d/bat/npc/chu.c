// servant.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int answer_inquiry();
//string kill_passenger(object who);
void create()
{
        set_name("楚留香", ({ "master chu", "chu", "master" }) );
        set("title", "盗帅");
		set("nickname", HIY "妙绝天下" NOR);
    set("reward_npc", 1);
    set("difficulty", 150); 

        set("gender", "男性");
        set("age", 34);       
        create_family("风雨飘香", 1, "隐士");

        set("long",
"他双眉被面长，充满粗犷的男性魅力，但那双清澈的眼晴，却又是那麽秀逸。他鼻子
挺直，象征坚强、决断的铁石心肠，他那薄薄的，嘴角上翘的嘴，看来也有些冷酷，但
只要他一笑起来，坚强就变作温柔，冷酷也变作同情，就像是温暖的春风吹过了大地。\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 100000000);
       
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "楚留香道：四年前见过枯梅大师一次，那次我是陪蓉儿她们去游华山时远远瞧过她一眼。 \n",
        }) );
      

        set("force", 77000);
        set("max_force", 7700);
        set("force_factor", 70);
        set("skill_public", 1);

        set("inquiry", ([
                "蝙蝠岛": (: answer_inquiry :),
        ]) );

        set_skill("force", 150);
        set_skill("unarmed", 120);
        set_skill("parry", 150);
        set_skill("dodge", 320);
 	    set_skill("move", 320);
 	    set_skill("literate", 150);

        set_skill("bibo-force", 150);
        set_skill("luoriquan", 200);
     set_skill("fengyu-piaoxiang", 320);
	    set_skill("stealing",320);

        map_skill("force", "bibo-force");
        map_skill("unarmed", "luoriquan");
        map_skill("dodge", "fengyu-piaoxiang");
     map_skill("move", "fengyu-piaoxiang");


        setup();

        carry_object(__DIR__"obj/whitecloth")->wear();

}
int answer_inquiry()
{
	object ob,room;
	ob=this_player();
    say("楚留香突然眼中放出异样的光芒，喃喃道：
蝙蝠岛，哦！我想起来了，胡铁花曾跟我提起他要去那办一件很要紧的事情，
阁下如果也感兴趣，可以去东海之滨等着。\n\n");
   message_vision("$N听了心中一动，顿时起了极大的兴趣，赶紧往海滨赶去.....\n", ob); 
   room = load_object("/d/bat/bfd1");
   if(room) ob->move(room);


    return 1;
	

}

void init()
{
//  object ob;
  ::init();
  add_action("do_qiecuo", "qiecuo");
/*  ob=this_player();
  if(ob->query("marks/killed_hu")) 
                kill_ob(ob);*/
 
}
void attempt_apprentice(object ob)
{

 command("say 为人师傅是不敢当的，这样好了，
我们来砌磋(qiecuo)一下，看看你三招内是否可以伤到我！");

}

int recognize_apprentice(object ob)
{
  if(!ob->query("marks/win_chu_time"))
	  return 0;
  if((time() - ob->query("marks/win_chu_time") ) > 900)
  {
    say("楚留香说道：你从我这学了不少了，我们来再砌磋(qiecuo)一下吧！\n");
    return 0;
  }
 return 1;
}

int do_qiecuo()
{
    mapping guild;
    int skee,dkee;
    object me,target;
	
	me=this_player();
	target=this_object();
	skee=target->query("kee");
	//if who have win master chu,and the time is not beyond 900 sec,then do this way
	if((time()-me->query("marks/win_chu_time"))<900)
	{
     command("say 你的功夫真不错，不用再切磋啦！\n");
	 return 1;
	}
	//if who have qiecuo,and the time have beyond 2 hours,then he can qiecuo
	if(time() - me->query("marks/qiecuo_last_time")>72000)
	{
     
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
	 say("\n楚留香笑嘻嘻道：一招．．．．\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n楚留香笑嘻嘻道：二招．．．．\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n楚留香笑嘻嘻道：三招．．．．\n");
	 dkee=target->query("kee");
     if(!(dkee<skee)) 
	 {
      say("楚留香笑嘻嘻道：三招已过，等你练好些再来吧！\n");
	  me->set("marks/qiecuo_last_time",time());
     }
	 else
	 {
            
      say("\n楚留香说道：你的功夫真不错，从今以后我们就相互学习吧！\n");
	  me->set("marks/win_chu_time",time());
	 }
	 return 1;
	}
    say("楚留香说道：你不久前才输给我！过两天再比吧！\n");
    return 1;
}


