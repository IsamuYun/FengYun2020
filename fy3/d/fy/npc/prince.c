// Tie @ fy3
#include <ansi.h>
inherit NPC;
int kill_him();
void create()
{
        set_name("С����", ({ "prince", "little prince"}) );
        set("gender", "����" );
        set("age", 12);
        set("long", "���ǵ�����ϵ�С���ӣ����ܳ谮��һ��\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
		  set_temp("kf_tufei",43);
        set("pursuer", 1);
set_skill("dodge", 100);
	set_skill("leadership",300);
	set_skill("strategy",300);
        set("intellgent",1);
         set("inquiry", ([
"������": "������ʲô�£���answer��\n",
        ]) );
set("chat_chance", 1);
	set("class","official");
 set("chat_msg", ({
                "С�����ſڵ�����"+HIR"��"NOR+"һ�������δ�����"+HIG"��"NOR+"��\n",
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

if(arg == "�ļ�¼" ) {
command("say �ã���ȥ�ɣ�\n");
	message_vision("$N����С���ӵĺ��棬�����ʹ���Ժ��\n", me);
		room = load_object("/d/fy/king");
		if(room) me->move(room);

}
}



