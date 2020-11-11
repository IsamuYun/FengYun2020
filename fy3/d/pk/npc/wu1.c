inherit NPC;

string ask_me();

void create()
{
        set_name("比赛使者", ({ "bisai shizhe", "shizhe","bisai" }));
        set("gender", "男性");
        set("age", 47);

        set("inquiry", ([
"准备": "你准备好了吗？开始了吗?（gone）\n",
"好了": "你准备好了吗？开始了吗?（gone）\n",
"开始": "你准备好了吗？开始了吗?（gone）\n",
        ]) );
 
        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        add_action("do_sign", "gone");
}
int do_sign()
{
        object me;
        string msg;
        object ob;

        me = this_player();
              ob = new("/d/pk/obj/ling");
           if(me->query_temp("pkok") == 1)
                  return notify_fail("唉！你已经有杀人证了还来？\n");
       message_vision("$n对$N道：“好，你就进去吧，祝你好运。”\n",
                       me, this_object());
             ob->set("srname",me->query("id"));
        ob->move(me);
         me->set_temp("pkok",1);        
        return 1;
}
