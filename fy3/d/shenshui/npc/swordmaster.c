// copy to /d/shenshui/npc/swordmaster.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("白三空", ({ "master bai", "master", "baisankong" }) );
        set("nickname", HIY"清平剑客"NOR);
        set("gender", "男性" );
        set("age", 54);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 20);
	set("attitude","peaceful");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 3);
        set("long",
"

\n"
	);
        create_family("清平山庄", 1, "庄主");

        set("combat_exp", 10000000);
        set("score", 200000);
        set("chat_chance", 10);
        set("chat_msg", ({
	"白三空摇头叹道：＂清平山庄横祸不断，人丁衰弱．．．＂\n"	
        }) );

        set_skill("move", 100);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("force", 100);
	set_skill("unarmed", 80);
	set_skill("bai-quan",80);
        set_skill("literate", 100);
	set_skill("sword",130);
	set_skill("qingpingsword",150);
        set_skill("qingpingforce",120);
        set_skill("chaos-steps",120);
	map_skill("force", "qingpingforce");
	map_skill("parry","qingpingsword");
        map_skill("sword","qingpingsword");
        map_skill("dodge","chaos-steps");
        map_skill("move","chaos-steps"); 
     	map_skill("unarmed","bai-quan"); 
        set("inquiry", ([
"白衣人": "白衣人的武功非同寻常，中原武林唯有五色帆船主方有可能胜他，
可惜我有伤在身，不能亲往，你愿意帮我走一趟吗？（answer）\n",
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/longsword")->wield();
carry_object(__DIR__"obj/kuzhi");
}
void init()
{
        object          me;
        add_action("do_answer","answer");
        ::init();
        if( interactive(me = this_player()) && !is_fighting() && !random(5)) {
                add_action("do_accept", "accept");
                call_out("greeting", 1, me);
        }

}
int greeting(object me)
{
if(me->query("gender") == "女性")
message_vision(HIY "\n$N对$n说道：你愿意改姓做我的义女吗？（accept yes/no）\n" NOR,
this_object(), me);
else
message_vision(HIY "\n$N对$n说道：你愿意改姓做我的义子吗？（accept yes/no）\n" NOR, 
this_object(), me);
        return 1;
}
/*
void attempt_apprentice(object me)
{
	command("smile");
        command("recruit " + me->query("id") );

}
*/
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","清平山庄剑童");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","清平山庄剑童");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","清平山庄剑手");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","清平山庄剑手");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","清平山庄剑士");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","清平山庄剑士");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","清平山庄剑士");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","清平山庄剑老");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","清平山庄剑老");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","清平山庄剑老");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","清平山庄剑仙");
                return ;
        } else
                student->set("title","清平山庄剑神");
                return ;
}

int do_accept(string arg)
{
	string name;
        if( arg != "yes" &&  arg != "no") 
                return notify_fail("你要接受什么？\n");
        if( arg == "yes") {
	name = (string) this_player()->query("name");
	name = "白"+name[2..];
	this_player()->set("name",name);
	this_player()->save();
        message_vision( HIY "$N说道：好！你以后就叫＂"+this_player()->query("name")+"＂，咱们就是一家人了！\n" NOR, this_object());
        this_player()->set("marks/白家人", 1);
        }
        else 
	command("sigh");
	return 1;
}
int do_answer(string arg)
{
        object shuzhi, me;
	me = this_player();  
        if(arg == "愿意" ) {		
	if( shuzhi = present("kuzhi", this_object())) {     
        command("say 好，够胆色！\n");
        command("say 这段白衣人削下的枯枝，你拿去给紫衣侯看一看，他就会明白了。\n");
        shuzhi->move(me);
        return 1;
        }
        say("白三空说道：这位" + RANK_D->query_respect(me) +
		",已经有人去了，你来晚了。\n");
        return 1;
        }
        return 1;
}
