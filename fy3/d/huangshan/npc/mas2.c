
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("柳无眉", ({ "master liu", "master","liu" }) );
    set("reward_npc", 1);
    set("difficulty", 150); 

        set("gender", "女性" );
        set("title", "黄山派掌门夫人");
        set("age", 26);
        set("int", 30);
        set("per", 30);
        set("apprentice_available", 50);
        create_family("黄山派", 3, "掌门");
	set("long",
		"柳无眉黄山派掌门夫人\n"
		);
        set("force_factor", 200);
        set("chat_chance", 5);
        set("chat_msg", ({
name()+"嘀咕道：噫．．我的温玉怎么不见了？\n",
        }) );
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 3000);
        set("force", 3000);

        set("combat_exp", 9999999);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("force", 100);
        set_skill("move", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set_skill("perception", 100);


        set_skill("yunwu-strike", 100);
        set_skill("siqi-sword", 120);
        set_skill("xianjing", 150);
        set_skill("liuquan-steps", 100);

        map_skill("unarmed", "yunwu-strike");
        map_skill("sword", "siqi-sword");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.siqi" :),
        }) );

	setup();
	carry_object(__DIR__"obj/yellowcloth")->wear();
        carry_object(__DIR__"obj/yusword")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
/*
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本夫人今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "女性" )
          {      command("say 我只收女弟子，你还是去拜我的夫君吧！");
          }
        else {

                command("smile");
                command("say 你日后可要光大黄山派哟！");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huangshan");
        add("apprentice_availavble", -1);
}
int accept_fight(object me)
{
                return 0;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","黄山派弟子");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","黄山派小侠");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","黄山派少侠");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","黄山派大侠");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","黄山派奇侠");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","黄山派长老");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","黄山派元老");
                return ;
        } else
                student->set("title","黄山派副掌门");
                return ;
}
*/
int accept_object(object who, object ob)
{
	if(ob->query("id") == "old jade")
	{
	command("smile");
	command("thank "+who->query("id"));
	if((int)ob->query("max_cure") < 10)
	call_out("give_pena",3,who);
	else
	call_out("give_reward",3,who);
	return 1;
	}

}
int give_reward(object who)
{
if(environment() != environment(who)) return 1;
if(!who->query("m_success/找玉石"))
        {
                who->set("m_success/找玉石",1);
                who->add("score",700);

        }
return 1;
}

int give_pena(object who)
{
if(environment() != environment(who)) return 1;
command("say 你竟然敢偷用本夫人的玉石？！！\n");
kill_ob(who);
who->kill_ob(this_object());
return 1;
}
