// farmer.c
inherit NPC;
#include <ansi.h>

void create()
{       
        set_name(HIG"茶农"NOR, ({ "farmer" }) );
        set("gender", "男性" );
        set("age", 33);
        set("long", "一位以耕种茶叶为生的农夫，拖着沉重的步伐，带着满身的汗水从茶园中回来。\n");
        set("combat_exp", 20);
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_msg_combat", ({
                "农夫叫道：杀人哪！杀人哪！\n",
                "农夫叫道：有土匪哪！光天化日下打劫哪！\n",
                (: command, "surrender" :),
        }) );
        setup();
/*      carry_object(__DIR__"obj/raincoat")->wear();
        carry_object(__DIR__"obj/sandals")->wear();*/
        add_money("coin", 20);
}
int accept_object(object me, object ob)
{
    me = this_player();
    if(me->query("shou_xincha")==0)
    {
        write("农夫说道：这不是你自己要来的茶票吧？我没收了！\n");
        call_out("destroying", 1, this_object(), ob);
        return 1;
    }
    if((string)ob->query("name")==YEL"海边茶票" NOR)
    {
        if(me->query("shou_xincha")==1)
        {
            command("say 好的，这是给风云城茶博士的新茶！\n");
        call_out("destroying", 1, this_object(), ob); 
        ob = new(__DIR__"obj/xcf");
        ob->move(me);
        tell_object(me,"农夫给了你一大包新茶。\n");
        return 1;
        }
        else if(me->query("shou_xincha")==2)
        {
            command("say 好的，这是给大理城品香居士的新茶！\n");        
        call_out("destroying", 1, this_object(), ob); 
        ob = new(__DIR__"obj/xcf1");
        ob->move(me);
        tell_object(me,"农夫给了你一大包新茶。\n");
        return 1;
        }
    }
    command("say 这好像不是我这里的茶票吧？\n");
}
