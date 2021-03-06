//TIE@FY3
inherit NPC;
#include <ansi.h>;
inherit F_MASTER;
void create()
{
	set_name("李玉函", ({ "master li", "master","li" }) );
    set("reward_npc", 1);
    set("difficulty", 150); 

	set("gender", "男性" );
        set("title", "黄山派掌门");
	set("age", 25);
	set("int", 30);
	set("per", 30);
        set("apprentice_available", 50);
        create_family("黄山派", 3, "掌门");
	set("long",
		"李玉函乃天下第一剑客李观鱼之子，出身拥翠山庄，因少年有为而被任为黄山派掌门\n"
		);
        set("force_factor", 20);
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
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("force", 100);
        set_skill("move", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("yunwu-strike", 100);
	set_skill("qiusheng-blade", 130);
	set_skill("xianjing", 150);
	set_skill("liuquan-steps", 100);

	map_skill("unarmed", "yunwu-strike");
        map_skill("blade", "qiusheng-blade");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "blade.jingsheng" :),
        }) );

	setup();
	carry_object(__DIR__"obj/greencloth")->wear();
        carry_object(__DIR__"obj/yuhuan")->wield();
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
                command("say 本掌门今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "男性" )
          {      command("say 我只收男弟子，你还是去拜我的夫人吧！");
          }
        else {

                command("smile");
                command("say 你一定要发扬光大黄山派的武功！");
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
void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
string what,where;
if(!arg) return 0;
if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
if((strsrch(what, "cang qiong") != -1 || strsrch(what, "all") != -1) &&
 (strsrch(where, "xiqiang") != -1 || strsrch(where, "西墙") != -1 ||
strsrch(where, "west wall") != -1 || strsrch(where, "wall") != -1))
 {
 {message_vision("$N对$n大吼一声：大胆！竟敢打先父遗物的主意！\n",this_object(),this_player());
 this_object()->kill_ob(this_player());
this_player()->start_busy(2);
return 1;
}
return 0;
}
}
