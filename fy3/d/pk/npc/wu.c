inherit NPC;

string ask_me();

void create()
{
        set_name("比赛使者", ({ "bisai shizhe", "shizhe","bisai" }));
        set("gender", "男性");
        set("age", 47);

        set("inquiry", ([
"杀人比赛": "你也想参加？（answer）\n",
"杀人": "你也想参加？（answer）\n",
"比赛": "你也想参加？（answer）\n",
        ]) );
 
        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        add_action("do_sign", "answer");
}
int do_sign()
{
        object me;
        string msg;
        object ob;

        me = this_player();
        message_vision("$n对$N道：“好，我看看你够不够资格。”\n",
                       me, this_object());
                if (me->query("pkover") > 1)
        {
                message_vision("$n抬头看了看$N，不屑道：你已经参加过了,明天吧！\n",
                               me, this_object());
                return 1;
        }
                if (me->query("combat_exp") < 1000000)
        {
                message_vision("$n抬头看了看$N，不屑道：“就你"
                               "这点本事？只好参加被杀大赛！”\n",
                               me, this_object());
                return 1;
        }
                if (me->query("sxwuqi" ) == 1)
        {
                message_vision("$n抬头看了看$N，不屑道：你不知道不可以带神兵吗？\n",me, this_object());
                return 1;
        }

        message_vision("$n点点头，对$N道：“好吧，你先进"
                       "去准备吧。”\n$N点点头，向北面的"
                       "准备室走去。\n", me, this_object());
        me->move("/d/pk/ready");
              me->set("pkover",1);        
message("vision", me->name() + "精神抖擞的走了进来。\n",
                environment(me), ({ me }));
        return 1;
}
