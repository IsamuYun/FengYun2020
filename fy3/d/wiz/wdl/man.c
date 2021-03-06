inherit NPC;
string ask_me(); 
int do_shouge(string arg); 
void reward(object me); 

void create()
{
        set_name("老农", ({ "old farmer", "farmer" }) );
        set("gender", "男性");
        set("age", 46);
        set("long",
                "一位年近五十的农夫。\n"
        );
        set_skill("blade", 10+random(50));
        set("inquiry", ([ 
"收庄稼" : (: ask_me :), 
"shouge" : (: ask_me :), 
]));
        setup();
        add_money("silver", 1);
        carry_object("/u/wudang/obj/liandao")->wield();

}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_shouge", "shouge");

}

string ask_me() 
{ 
object me = this_player(); 

if (this_object()->is_busy()) 
return "我现在很忙，你等会吧？"; 
if (me->query("combat_exp") > 100000) 
return "让您老干这个未免屈尊了吧？"; 

if (me->query("kee") < 50) 
return "你看起来有点累，歇歇喝点水，这天太热了。"; 

{ 
me->set_temp("laonong/shouge", 1); 
return "好！你帮我收割庄稼吧(shouge)。"; 
}
}

int do_shouge(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("你现在正忙。\n"); 

if (! me->query_temp("laonong/shouge")) 
{ 
message_vision("$n拿起镰刀，弯下腰去开始收割庄稼。" 
"就听见$N对$n道：这不是你的任务你抢什么？\n", 
this_object(), me); 
return 1; 
} 

message_vision("$n拿起镰刀，顶着烈日弯下腰去开始收割庄稼，$N看了点了点头。\n", 
this_object(), me); 
reward(me); 
return 1; 
} 

void reward(object me) 
{ 
object coin; 

me->delete_temp("laonong/shouge"); 

coin = new("/obj/money/coin"); 
coin->set_amount(20 + random(100)); 
coin->move(this_player()); 
this_object()->start_busy(2);
message_vision("$N对$n道：这是给你的工钱。\n", 
this_object(), me); 
if (me->query("combat_exp") < 100000) 
{
me->add("potential", 3); 
me->add("combat_exp", 10 + random(10)); 
} 
me->receive_damage("kee", 30); 
me->start_busy(4); 
} 

