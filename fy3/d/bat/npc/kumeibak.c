// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("枯梅大师", ({ "master kumei", "kumei", "master"}) );
        set("gender", "女性");
        set("age", 59);
        set("nickname", HIW"铁仙姑"NOR);
        set("title", "华山派第十六代掌门");

        set("str", 30);
        set("agi", 50);
        set("int", 40);
	set("per", 40);

        set("max_gin", 2000);
        set("max_kee", 50000);
        set("max_sen", 549);
        set("eff_gin", 2000);
        set("eff_kee", 50000);
        set("eff_sen", 549);
        set("gin", 2000);
        set("kee", 50000);
        set("sen", 549);

        set("max_force", 9000);
        set("force", 9000);
        set("force_factor", 30);

	set("attitude","friendly");

        set("long",
"这是一个白发苍苍的老妇，一张干枯瘦削的脸上满是伤疤，耳朵缺了半个，
眼睛也少了一只，剩下的一只眼睛半开半合，开合之间，精光暴射，无论谁也
不敢逼视。她身子很瘦小，但却有种说不出来的威严，无论谁人只要瞧上她 
一眼，连说话的声音都会压低些。\n"
	);
        create_family("华山派", 16, "掌门");
	set("student_title","弟子");
        set("combat_exp", 1500000);

	set("chat_chance_combat",50);
        set("chat_msg_combat", ({
		(: perform_action,"sword.pochan" :),
		(: perform_action,"sword.poqi" :),
        }) );

        set_skill("sword", 150);
        set_skill("wuzheng-force", 220);
        set_skill("literate", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 70);
	set_skill("dugu-sword", 140);
	set_skill("meng-steps", 150);
	set_skill("force", 90);
        set_skill("parry", 90);
        set_skill("move", 100);

       	map_skill("sword", "dugu-sword");
       	map_skill("parry", "dugu-sword");
       	map_skill("dodge", "meng-steps");
       	map_skill("move", "meng-steps");
       	map_skill("force", "wuzheng-force");

        setup();
        carry_object(__DIR__"obj/landuan")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}

void attempt_apprentice(object me)
{
	if(me->query_skill("sword",1)<100)
	{
	command("say 你对剑术所知甚少，竟然想来拜我！");
		return;
	}
	if(me->query_skill("dodge",1)<100)
	{
	command("say 阁下的身法似乎不能学武啊！");
		return;
	}
	if(me->query("marks/杀楚留香"))
	{
	command("smile");
        command("recruit " + me->query("id") );
        me->delete("marks/杀楚留香");
		return;
	}
	else
	{
		command("say 老身在此世上仇家倒不多，只有一人会坏我的大事");
		return;
	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","华山派弟子");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","华山派小侠");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","华山派少侠");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","华山派大侠");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","华山派奇侠");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","华山派长老");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","华山派元老");
                return ;
        } else
                student->set("title","华山派副掌门");
                return ;
}