// farmer.c
inherit NPC;
#include <ansi.h>

void create()
{       
        set_name(HIG"茶农"NOR, ({ "farmer" }) );
        set("gender", "男性" );
        set("age", 60);
        set("long", "一位以满脸沧桑的老农夫，脸上的皱纹仿佛无声的诉说着他一生的坎坷。\n");
        set("combat_exp", 20);
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_msg_combat", ({
                "老农夫喊道：来人哪！救命哪！！\n",
                "老农夫喊道：天哪！我安分守己一辈子居然还会惨遭如此横祸．．．\n",
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
        write("老农夫说道：这不是你自己要来的茶票吧？我没收了！\n");
        call_out("destroying", 1, this_object(), ob);
        return 1;
    }
    if((string)ob->query("name")==YEL"武当茶票" NOR)
    {
        if(me->query("shou_xincha")==1)
        {
            command("say 好的，这是给风云城茶博士的新茶！\n");
        call_out("destroying", 1, this_object(), ob); 
        ob = new(__DIR__"obj/xcf");
        ob->move(me);
        tell_object(me,"老农夫给了你一大包新茶。\n");
        return 1;
        }
        else if(me->query("shou_xincha")==2)
        {
            command("say 好的，这是给大理城品香居士的新茶！\n");        
        call_out("destroying", 1, this_object(), ob); 
        ob = new(__DIR__"obj/xcf1");
        ob->move(me);
        tell_object(me,"老农夫给了你一大包新茶。\n");
        return 1;
        }
    }
    command("say 这好像不是我这里的茶票吧？\n");
}
