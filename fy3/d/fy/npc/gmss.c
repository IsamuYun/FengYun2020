// gaiming_shusheng.c by chen
#include <ansi.h>
#include <login.h>
inherit NPC;

void create()
{
set_name("改名书生", ({ "shusheng" }));
        set("title", "金科探花" );
        set("shen_type", 1);

        set("str", 50);
        set("gender", "男性");
        set("age", 25);

        set("long", @LONG
这个改名的书生是个爱财如命的人。如果你想改名
只要给钱他,他就会帮你改个你喜欢的名字!!
LONG
        );

        set("combat_exp", 15000000);

        set("attitude", "friendly");
set("chat_msg", ({
              (: random_move :)
        }) );

        set("inquiry", ([
                "改名" : "你考虑清楚了吗？改名很重要的事情啊!(changename)",
        ]));

        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_name","changename");
}
void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say("改名书生笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
                        "，进来喝杯茶吧！\n");
                break;
        case 1 :
                say("改名书生惊恐的道：哟！这位" + RANK_D->query_respect(ob) +
                        "您想改名吗？\n");
                break;
        }
}

int accept_object(object who, object ob)
{

        if (ob->query("money_id") && ob->value() >= 50000000)
        {
                tell_object(who, 
     "改名书生高兴地说到：好吧，哪您想取个什么样的名字\n");
                tell_object(who, HIR"请您自己输入：改 新的中文名字\n"NOR);
                who->set_temp("fee_paid",1);
                return 1;
        }
        else if (ob->query("money_id") && ob->value() < 50000000)
        {
                tell_object(who, 
     "改名书生嘿嘿的奸笑,道：就这些钱？你以为我是穷光蛋啊，你想改就出多点吧。\n");
                return 0;
        }

        return 0;
}

int do_name(string target)
{
        object me;
        string old_name;
        me = this_player();
        old_name = me->query("name");

        if( !me->query_temp("fee_paid") )
                return 
     notify_fail("改名书生冷冷地说道：您可要细想好呀！\n");

        if( !target || target==" ") return notify_fail( @TEXT
改名书生告诉你，改名字要这样打：changename <新名字>
TEXT
        );

        if( old_name == target )
                return 
     notify_fail("落第书生惊讶地对你说到：您的钱是不是想送给我？\n");

        command("chat " + old_name + "改名为：" + target + 
    "。大家以后别认错了人！哈哈......\n");
        me->delete_temp("fee_paid");
        me->set("name", target);
		me->save();
        return 1;
}
