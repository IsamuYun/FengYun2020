inherit NPC;
void create()
{
        set_name("陆小凤", ({ "lu", "xiaofeng", "xiao feng" }) );
        set("gender", "男性");
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("age", 34);
	set("title","心有灵犀一点通");
        set("long",
"四条眉毛的陆小凤\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("chat_chance", 10);
        set("chat_msg", ({
                "陆小凤喃喃道：老刀把子到底是谁？？？\n",
        }) );
        set("force", 4000);
        set("max_force", 2200);
        set("force_factor", 100);
        set_skill("force", 100);
        set_skill("unarmed", 100);
set("inquiry",(["灵犀一指":"我要看看你是不是有这个天分，想试试吗(fight lu)？\n"]));
        set_skill("parry", 100);
        set_skill("dodge", 580);
	set_skill("move", 150);
        setup();

	carry_object("/obj/cloth")->wear();
}
void lose_enemy( object winner )
{
command("say 这位" + RANK_D->query_respect(winner) + "，你的工夫不错\n，可以学习我留在墙上的灵犀一指了");
winner->set_temp("mark/lu",1);
}
void win_enemy( object loser )
{
command("say 这位" + RANK_D->query_respect(loser) + "其蠢如猪，纵有绝世武功又能如何？");
}

int accept_object(object who, object ob)
{
 object silk,silk1;
 if(ob->query("id") == "xzhihuan")
  {
   command("say 这位" + RANK_D->query_respect(who)+ "，真没想到你能把我的修好送来,这是给你的奖励！\n");
   silk= new("/questobj/big");
silk->move(who);
        tell_object(who,"陆小凤给你一个"+silk->query("name")+"。\n");
   //silk1->move(this_object());
   //command("give jin-nang to " + who->query("id"));
who->add("bigtasks",1);
   return 1;
   }
 if(ob->query("id") == "letter") 
   {
 if(ob->query("pname") != who->query("name")) 
   {
    tell_object(who,query("name") + "说道：这不是你的，没收。\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(who->query("letter") < time())
   {
    tell_object(who,query("name") + "说道：哎，晚了，你来晚了！\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(ob->query("toname") == query("name"))
  {
   command("say 感谢这位远道把密函送来，这是给你的回函,切记要保管好！！\n");
   who->set_temp("nofly",0);
   silk1 = new("/d/dali/obj/huihan");
   silk1->set("pname",who->query("name"));
   silk1->move(who);
   return 1;
  }
  }
tell_object(who,query("name") + "说道：这不是我想要的。\n");
 return 0;
}

