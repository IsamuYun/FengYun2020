inherit NPC;
void create()
{
        set_name("½С��", ({ "lu", "xiaofeng", "xiao feng" }) );
        set("gender", "����");
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("age", 34);
	set("title","������Ϭһ��ͨ");
        set("long",
"����üë��½С��\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("chat_chance", 10);
        set("chat_msg", ({
                "½С���૵����ϵ����ӵ�����˭������\n",
        }) );
        set("force", 4000);
        set("max_force", 2200);
        set("force_factor", 100);
        set_skill("force", 100);
        set_skill("unarmed", 100);
set("inquiry",(["��Ϭһָ":"��Ҫ�������ǲ����������֣���������(fight lu)��\n"]));
        set_skill("parry", 100);
        set_skill("dodge", 580);
	set_skill("move", 150);
        setup();

	carry_object("/obj/cloth")->wear();
}
void lose_enemy( object winner )
{
command("say ��λ" + RANK_D->query_respect(winner) + "����Ĺ��򲻴�\n������ѧϰ������ǽ�ϵ���Ϭһָ��");
winner->set_temp("mark/lu",1);
}
void win_enemy( object loser )
{
command("say ��λ" + RANK_D->query_respect(loser) + "����������о����书������Σ�");
}

int accept_object(object who, object ob)
{
 object silk,silk1;
 if(ob->query("id") == "xzhihuan")
  {
   command("say ��λ" + RANK_D->query_respect(who)+ "����û�뵽���ܰ��ҵ��޺�����,���Ǹ���Ľ�����\n");
   silk= new("/questobj/big");
silk->move(who);
        tell_object(who,"½С�����һ��"+silk->query("name")+"��\n");
   //silk1->move(this_object());
   //command("give jin-nang to " + who->query("id"));
who->add("bigtasks",1);
   return 1;
   }
 if(ob->query("id") == "letter") 
   {
 if(ob->query("pname") != who->query("name")) 
   {
    tell_object(who,query("name") + "˵�����ⲻ����ģ�û�ա�\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(who->query("letter") < time())
   {
    tell_object(who,query("name") + "˵�����������ˣ��������ˣ�\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(ob->query("toname") == query("name"))
  {
   command("say ��л��λԶ�����ܺ����������Ǹ���Ļغ�,�м�Ҫ���ܺã���\n");
   who->set_temp("nofly",0);
   silk1 = new("/d/dali/obj/huihan");
   silk1->set("pname",who->query("name"));
   silk1->move(who);
   return 1;
  }
  }
tell_object(who,query("name") + "˵�����ⲻ������Ҫ�ġ�\n");
 return 0;
}

