// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("兴国大师", ({ "master xing", "master", "xing" }) );

        set("gender", "男性");
    set("reward_npc", 1);
    set("difficulty", 100); 
	set("class","xingguo");

        set("age", 74);
        set("attitude", "peaceful");
        set("class", "xingguo");
	set("student_title","大师");
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
        }) );
        set("atman", 3000);
        set("max_atman", 3000);
        set("force", 15000);
        set("max_force", 15000);
        set("force_factor", 5);
        set("mana", 3000);
        set("max_mana", 3000);
		set("max_kee",500000);
        set("combat_exp", 100000000);
        set("score", 9000);
        set_skill("unarmed", 300);
		set_skill("luoriquan", 1000);
        set_skill("force", 700);
        set_skill("literate", 480);
        set_skill("move", 500);
        set_skill("parry", 320);
        set_skill("magic", 1000);
        set_skill("lotus-steps", 1000);
        set_skill("lotusforce", 1000);
        set_skill("buddhism", 1000);
        set_skill("essencemagic", 1000);
        map_skill("unarmed", "luoriquan");
        map_skill("force", "lotusforce");
        map_skill("magic", "essencemagic");
        create_family("兴国禅寺", 3, "住持");
        setup();
	carry_object("/obj/cloth")->wear();

}

void attempt_apprentice(object ob)
{
	if( ob->query("class")&&ob->query("class") != "xingguo")
	{
	command("stare");
	command("say 你已经有自己的门派了！\n");
	}
	else if( ob->query("national") == "蒙古族" )
	{
	command("smile");
	command("say 很好！我兴国禅寺就靠你来发扬光大了！\n");
            command("recruit " + ob->query("id") );
	}
	else
	command("say 兴国禅寺只收蒙古族人！\n");
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xingguo");
}
int accept_fight(object me)
{
        if( (string)me->query("class")=="bonze" )
                command("say 阿弥陀佛！出家人戒逞强恶斗！老衲不敢违反清规。");
        else
                command("say 施主既然身负绝艺，老衲佩服便是，也不必较量了。");

        return 0;
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","兴国禅寺大师");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","兴国禅寺罗汉");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","兴国禅寺金刚");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","兴国禅寺高僧");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","兴国禅寺圣僧");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","兴国禅寺神僧");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","兴国禅寺活佛");
                return ;
        } else
                student->set("title","兴国禅寺副主持");
                return ;

}

