// waiter.c

inherit NPC;
int give_him();
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("读千里", ({ "duqianli" }) );
        set("gender", "男性" );
        set("age", 81);
        set("title", CYN "才高八斗" NOR);
        set("long",
                "这位老板不但才高八斗，而且还是当今皇太子的老师。\n");
        set("combat_exp", 500000);
        	  set_temp("kf_tufei",5);
        set("pursuer", 1);
set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([
                __DIR__"obj/book" : 10,
                __DIR__"obj/book3" : 20,
                __DIR__"obj/book4" : 20,
                __DIR__"obj/book5" :33,
                __DIR__"obj/book6": 22,
                __DIR__"obj/book7":22,
                __DIR__"obj/book8":11,
                __DIR__"obj/book9":10,
        "/obj/weapons/swordbook":5,
        "/obj/weapons/bladebook":5,
        "/obj/weapons/staffbook":5,
		"/obj/weapons/ringbook":5,
		"/obj/weapons/hammerbook":5,
		"/obj/armors/headbook":5,
		"/obj/armors/clothbook":5,
		"/obj/armors/neckbook":5,
		"/obj/armors/shieldbook":5,
		"/obj/armors/waistbook":5,
		"/obj/armors/wristsbook":5,
		"/obj/armors/fingerbook":5,
		"/obj/armors/bootsbook":5,
        "/d/bat/npc/obj/qfbook":10,

        ]) ); 
        set_skill("unarmed",50);
        set_skill("dodge",50);
        set("inquiry", ([
                "墨" : (: give_him :),
                "mo" : (: give_him :),
        ]));
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
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
message_vision("$N摇头晃脑地低吟道：良时不再至，离别在须臾。屏营衢路侧．．。\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N望了$n一眼，低哼道：结发为夫妻，恩爱两不疑。欢娱在今夕．．。\n",this_object(),ob);
                        break;
        }
}
int give_him()
{
        object me , obj;
        me = this_player();
        if( !query("given")) {
        obj = new(__DIR__"obj/mo");
        message_vision("$N说道：既然你对这个感兴趣，我就成全你了，读千里给了$n一块端砚。\n",this_object(), me);
        obj->move(me);
        set("given",1);
        return 1;
        }
        return 0;
}

void reset()
{
delete("given");
}
int accept_object(object who, object ob)
{
  object silk;
if(ob->query("id") == "qypu")
        {
command("say 感谢这位" + RANK_D->query_respect(who)+ "，我一直想找到这本书，这是给你的奖励！\n");
silk = new("/questobj/big");
silk->move(who);
        tell_object(who,"读千里给你一个"+silk->query("name")+"。\n");
//silk->move(this_object());
//command("give jin-nang to " + who->query("id"));
who->add("bigtasks",1);
        return 1;
        }
        tell_object(who,"读千里说道：这不是我想要的。\n");
        return 0;
}

