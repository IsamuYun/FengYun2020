// Tie @ fy3
#include <ansi.h>
inherit NPC;
int kill_him();
void create()
{
        set_name("小公子", ({ "prince", "little prince"}) );
        set("gender", "男性" );
        set("age", 12);
        set("long", "这是当今皇上的小公子，最受宠爱的一个\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
		  set_temp("kf_tufei",43);
        set("pursuer", 1);
set_skill("dodge", 100);
	set_skill("leadership",300);
	set_skill("strategy",300);
        set("intellgent",1);
         set("inquiry", ([
"见王妃": "想见我娘，什么事？（answer）\n",
        ]) );
set("chat_chance", 1);
	set("class","official");
 set("chat_msg", ({
                "小公子信口道：狂"+HIR"风"NOR+"一翻滚，何处不是"+HIG"云"NOR+"。\n",
        }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: ccommand, "alert" :),
        }) );
	setup();
	add_money("gold", 5);
        carry_object(__DIR__"obj/fycloth")->wear();
}
 void init()
{
add_action("do_answer","answer");
}
int do_answer(string arg)
{
object me;
	object room;
	me = this_player();

if(arg == "改记录" ) {
command("say 好，你去吧！\n");
	message_vision("$N跟着小公子的后面，来到皇宫内院。\n", me);
		room = load_object("/d/fy/king");
		if(room) me->move(room);

}
}



