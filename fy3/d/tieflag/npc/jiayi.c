// jiayi.c

inherit NPC;

void create()
{
    set_name("无名夫人",({"old woman","woman"}));
    set("long","她当年定是天香国色，可是现在...\n");
    set("gender","女性");
    set("age",42);
    set("skill_public",1);  
    set("no_arrest",1);
    set("int",22);
    set("cor",0);
    set("per",0);
    set("con",0);
    set("cps",20);
    set("agi",0);
    set("gin",1000);
    set("max_gin",1000);
    set("eff_gin",1000);
    set("max_sen",1000);
    set("sen",1000);     
    set("eff_sen",1000);
    set("combat_exp",0);  
    set_skill("force",100);
    set_skill("jiayiforce",75);
    set("force",100000);
    set("max_force",100000);
    set("force_factor",2000);
    map_skill("force","jiayiforce");
    set("attitude", "friendly");
	set("chat_chance",2);
	set("chat_msg",({
		"夫人说道：“武道禅宗，嫁衣神功”\n",
    }) );
    setup();
    carry_object("obj/cloth")->wear(); 
    carry_object(__DIR__"obj/jiabook");  
    add_money("silver",130);
}
int recognize_apprentice(object ob)
{
        if(ob->query("marks/嫁衣") )
              return 1;
}                      
