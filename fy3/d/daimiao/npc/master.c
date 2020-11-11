// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("羽天白", ({ "master yu", "master"}) );
        set("nickname", HIR "万胜刀魔" NOR);
    set("reward_npc", 1);
    set("difficulty", 100); 
	set("class","mojiao");
        set("gender", "男性" );
        set("age", 64);
	set("attitude","friendly");
        set("max_force", 75000);
        set("force", 75000);
        set("force_factor", 30);
        set("long",
"
羽天白是西方神教中的教主，羽天白的来历谁也不清楚，
也没人敢问。凡是问过或知道羽天白来历的人都不明不白的
消失了。
\n"
	);
        create_family("西方神教", 1, "教主");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "dodge.lianhuanbabu" :),
                (: perform_action, "blade.tiandirenmo" :),
                (: exert_function, "mihun" :)
        }) );
        set("combat_exp", 100000000);
        set("score", 200000);

        set_skill("move", 200);
        set_skill("parry",400);
        set_skill("dodge", 200);
        set_skill("force", 500);
        set_skill("literate", 500);
	set_skill("unarmed",200);
	set_skill("demon-steps",1000);
	set_skill("demon-strike",1000);
	set_skill("demon-force",1000);
	set_skill("blade",1000);
	set_skill("demon-blade",1000);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
	map_skill("blade","demon-blade");
	map_skill("parry","demon-blade");
        set("inquiry", ([
                "白天羽" : (: kill_him :),
                "万马堂" : (: kill_him :),
        ]));
        setup();
        carry_object(__DIR__"obj/wufu")->wear();
	carry_object(__DIR__"obj/lou")->wield();

}
void attempt_apprentice(object ob)
{
	if( ob->query("class")&&ob->query("class") != "mojiao")
	{
	command("stare");
	command("say 你已经有自己的门派了！\n");
	}
	else if( ob->query("national") == "蒙古族" )
	{
	command("smile");
	command("say 哈哈，老夫后继有人啦！\n");
            command("recruit " + ob->query("id") );
	}
	else
	command("say 魔教只收蒙古族人！\n");
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "mojiao");
}
int kill_him()
{
	object me;
	me = this_player();
	command("say 看来你已经知道我的来历了！！ \n");
	this_object()->kill_ob(me);
	me->kill_ob(this_object());
	return 1;
}
int accept_object(object me, object obj)
{
	if(obj->query("for_bandit"))
	{
	command("? "+me->query("id"));
        command("say 你．．你杀了本教的人，偷了本教的东西，还敢来愚弄老夫！\n");
	this_object()->kill_ob(me);
	me->kill_ob(this_object());
	return 1;
	}
	if(obj->query("for_bandit2"))
	{
	me->set_temp("for_bandit",1);
	command("smile");
	command("say 好，很好.\n");
	return 1;	
	}
	return 0;
}
void re_rank(object student)
{
	int exp;
	exp = (int) student->query("level");
	if( exp <= 10 ) {
		student->set("title","西方神教教徒");
		return ;	
	} else if ( exp <= 20 ) {
		student->set("title","西方神教副堂主");
		return ;
        } else if ( exp <= 30 ) {
                student->set("title","西方神教堂主");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","西方神教副坛主");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","西方神教坛主");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","西方神教副舵主");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","西方神教舵主");
                return ;
        } else if ( exp <= 80 ) {
                student->set("title","西方神教护法");
                return ;
        } else if ( exp <= 90 ) {
                student->set("title","西方神教大护法");
                return ;
        } else if ( exp <= 100 ) {
                student->set("title","西方神教长老");
                return ;
        } else if ( exp <= 120 ) {
                student->set("title","西方神教大长老");
                return ;
        } else 
                student->set("title","西方神教副教主");
                return ;

}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if(ob) 
        ob->set("marks/killyu",1);
        ::die();
}
