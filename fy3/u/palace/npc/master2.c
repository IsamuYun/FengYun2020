
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("蓝天锤", ({ "master lan", "lan","master" }) );
	set("gender", "男性" );
    set("reward_npc", 1);
    set("difficulty", 150); 

        set("title",HIB "蓝大先生" NOR);
        create_family("天锤山庄", 1, "庄主");
	set("long",
		"蓝天锤的一柄大锤用的出神入化．．．
每年都和帝王谷主绝顶一战，致今胜负不分． 
蓝天锤的脾气爆如烈火，经常无缘无故的将弟子打成死伤或逐出墙门．\n"
		);
        set("chat_chance", 1);
        set("chat_msg", ({
"蓝天锤笑骂道：这个箫老儿，又和他不分胜负．\n",
        }) );
        set("combat_exp", 99999999);
        set("score", 90000);
        set_skill("unarmed", 1000);
        set_skill("hammer", 1000);
        set_skill("force", 500);
        set_skill("parry", 100);
        set_skill("literate", 700);
		set("max_force",50000);
		set("force",50000);
	set_skill("dodge", 300);
	set("class","tianchui");

	set_skill("pangu-hammer", 1000);
	set_skill("pofeng-strike", 1000);
	set_skill("putiforce", 1000);
	set_skill("nodust-steps", 1000);

	map_skill("unarmed", "pofeng-strike");
        map_skill("hammer", "pangu-hammer");
        map_skill("force", "putiforce");
        map_skill("parry", "pangu-hammer");
        map_skill("dodge", "nodust-steps");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "hammer.kaitianpidi" :),
		(: cast_spell, "shrink" :),
        }) );
	setup();
        carry_object(__DIR__"obj/bluecloth")->wear();
        carry_object(__DIR__"obj/jumbohammer")->wield();
}

void attempt_apprentice(object ob)
{
	if( ob->query("class")&&ob->query("class") != "tianchui")
	{
	command("stare");
	command("say 你已经有自己的门派了！\n");
	}
	else if( ob->query("national") == "蒙古族" )
	{
	command("smile");
	command("say 很好！我天锤山庄就靠你来发扬光大了！\n");
            command("recruit " + ob->query("id") );
	}
	else
	command("say 天锤山庄只收蒙古族人！\n");
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianchui");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","天锤派弟子");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","天锤派小侠");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","天锤派少侠");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","天锤派大侠");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","天锤派奇侠");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","天锤派长老");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","天锤派元老");
                return ;
        } else
                student->set("title","天锤派副掌门");
                return ;
}

