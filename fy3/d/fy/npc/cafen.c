// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("胡英", ({ "huying" }) );
	set("gender", "男性" );
	set("title", "棺材店老板");
	set("age", 55);
	set("long",
		"这位老人的脸上布满绉纹．．．\n");
	set("combat_exp", 50);
		  set_temp("kf_tufei",7);
        set("pursuer", 1);
set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		__DIR__"obj/zhiqian":4,
                __DIR__"obj/zhihua":5,
                "/obj/paper_seal":100,
	]) );
	set_skill("unarmed",5);
	setup();
	carry_object("/obj/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N看了$n一眼道：木棺没货，都订了，酞多人死了。\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N向$n问道：谁死了？\n",this_object(),ob);
                        break;
        }
}

int accept_object(object who, object ob)
{
  object silk;
if(ob->query("id") == "foolguancai")
	{
command("heihei");
command("say 这位" + RANK_D->query_respect(who)+ "，你能作成这样也算不错了,还好材料还能用，我就帮你一下吧！\n");
silk = new("/questobj/obj/guancai2");
silk->move(this_object());
command("give goodguancai to " + who->query("id"));
add("given",1);
	return 1;
	}
        tell_object(who,"胡英说道：这里只接定单和死人。\n");
        return 0;
}
