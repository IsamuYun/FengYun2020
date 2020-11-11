
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("葛伦", ({ "master gelun", "master","gelun" }) );
	set("gender", "男性" );
    set("reward_npc", 1);
    set("difficulty", 150); 
	set("class","dazhao");

	set("age", 99);
    set("apprentice_available", 20);
    create_family("大昭寺", 20, "主持");
	set("long",
		"葛伦高僧已在大昭寺主持多年。男女弟子遍布关外。\n"
		);
	set("inquiry", ([
		"舍利子": "嗯....舍利子.....在舍利塔里。\n",
		"普松": "普松在大昭寺的木屋里。",
	]) );
    set("combat_exp", 100000000);
    set("score", 90000);
    set_skill("unarmed", 550);
    set_skill("staff", 1000);
    set_skill("force", 300);
    set_skill("parry", 1000);
    set_skill("literate", 300);
	set_skill("iron-cloth", 1000);

	set_skill("bloodystrike", 1000);
	set_skill("cloudstaff", 1000);
	set_skill("bolomiduo", 1000);
	set_skill("buddhism", 500);
    set_skill("jin-gang", 1000);


	map_skill("unarmed", "bloodystrike");
    map_skill("force", "bolomiduo");
    map_skill("literate", "buddhism");
    map_skill("iron-cloth", "jin-gang");
    map_skill("staff", "cloudstaff");
    map_skill("parry", "cloudstaff");

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
        }) );
	setup();
	carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
}
void attempt_apprentice(object me)
{
	if( me->query("class")&&me->query("class") != "dazhao")
	{
	command("stare");
	command("say 你已经有自己的门派了！\n");
	}
	else if( me->query("national") == "藏族" )
	{
	command("smile");
	command("say 很好！本寺院就盼你来发扬光大了！\n");
            command("recruit " + me->query("id") );
	}
	else
	command("say 大昭寺只收藏族之人！\n");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dazhao");
}
 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","大昭寺弟子");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","大昭寺罗汉");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","大昭寺高僧");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","大昭寺圣僧");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","大昭寺法王");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","大昭寺活佛");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","大昭寺副主持");
                return ;
        } else
                student->set("title","大昭寺主持");
                return ;

}
