#include <ansi.h>
inherit NPC;

void create()
{
	set_name("东三娘", ({ "woman" }) );
	set("gender", "女性" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
这窄小的、黑暗的房子，就是她的全部生命，全部世界。 
在这里没有年，没有月，也分不出日夜。
她只能永远在黑暗中等着，赤裸裸的等着，等到她死。
如果你没有任何负疚的话可以(ｅｎｊｏｙ)。\n
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

	setup();
}

int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您一定会．．．．！");
        return 1;
}

void init()
{
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
object me;
object *inv;
int maxgin,maxkee, maxsen;
int i;
	me = this_player();
message_vision("东三娘的手几乎比男人还粗野，喘息着道：“来呀……$N已经来了，还等什么?",this_object(),me);
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			destruct(inv[i]);
		}
message_vision("$N内心涌起一种莫名的深深的悲哀．．．．\n", me);
	me->apply_condition("hualiu_poison",10+random(20));
	return 1;

}
