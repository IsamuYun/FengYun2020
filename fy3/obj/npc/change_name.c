// dazhuang.c 金牙大状
#include <ansi.h>
#include <login.h>
inherit NPC;

void create()
{
        set_name("金牙大状", ({ "jinya_dazhuang", "jingya", "dazhuang" }));
        // set("title", "小如儿的大伯");
        set("nickname", "改名先生");
        set("shen_type", 1);

        set("str", 50);
        set("gender", "男性");
        set("age", 55);

        set("long", @LONG
这个金牙大状，生的方面大耳，面色红润，须发尽白。
据说他能改变人的命运。但他爱财如命，如果你没钱
休想叫他帮你。
LONG
        );

        set("combat_exp", 95000000);

        set("attitude", "friendly");
        set("inquiry", ([
                "改名" : "你考虑清楚了吗？该名可要交钱的。",
        ]));

        setup();
        carry_object("/obj/cloth/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_name","改");
}
void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say("金牙大状笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
                        "，进来喝杯茶吧！\n");
                break;
        case 1 :
                say("金牙大状惊恐的道：哟！这位" + RANK_D->query_respect(ob) +
                        "您找我有事吗？\n");
                break;
        }
}

int accept_object(object who, object ob)
{

        if (ob->query("money_id") && ob->value() >= 20000000)
        {
                tell_object(who, "金牙大状高兴地说到：好吧，哪您想取个什么样的名字\n");
                tell_object(who, "请您自己输入：改 新的中文名字\n");
                who->set_temp("fee_paid",1);
                return 1;
        }
        else if (ob->query("money_id") && ob->value() < 20000000)
        {
                tell_object(who, "金牙大状嘿嘿的奸笑,道：就这些钱？我才不干，你还是去吧。\n");
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
                return notify_fail("金牙大状冷冷地说道：不管要我做什麽，您可要细想好呀！\n");

        if( !target || target==" ") return notify_fail( @TEXT
金牙大状告诉你，改名字要这样打：改 <新名字>
TEXT
        );

        if( old_name == target )
                return notify_fail("金牙大壮惊讶地对你说到：您的钱是不是想送给我？\n");

        command("chat " + old_name + "从现在开始改名为：" + target + "。大家以后别认错了人！哈哈......\n");
        me->delete_temp("fee_paid");
        me->set("name", target);

        return 1;
}
