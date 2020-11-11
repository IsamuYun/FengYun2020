// tea_waiter.c

inherit NPC;
inherit F_VENDOR;
int do_gongzuo();
int do_lost();
#include <ansi.h>

void create()
{
        set("inquiry", ([
                "工作" : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
                "lost" : (: do_lost :),
                "茶叶" : "最近该去收新茶了，但是人手却不够．．．．．"
        ]));
        set_name(HIW"品香居士" NOR , ({ "jushi" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "一位白发长髯的老者，对品茶有独到之处。\n");
        set("combat_exp", random(100000)+random(2000000));
        set("attitude", "friendly");
        set("rank_info/respect", "品茶居士");
        set("vendor_goods", ([
                "/obj/example/teapot": 10,
                "/obj/example/dumpling": 10,
                "/obj/example/chicken_leg": 20,
        ]) );
        setup();
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
        switch( random(3) ) {
                case 0:
                        say( "品茶居士笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "品茶居士用毛巾抹了抹靠门的一张桌子，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say( "品茶居士说道：这位" + RANK_D->query_respect(ob)
                                + "，进来尝尝才采的新茶叶。哇! 好香啊!...\n");
                        break;
        }
}

int do_gongzuo()
{ 
    object ob,me;
        
    me = this_player();
    if((me->query("class")) == "dali")
    {
        message_vision("$N说道：哇！您是大理的老乡，请近来坐，我哪好意思麻烦您呀！\n",this_object(), me);
        return 1;
    }
    if(me->query("score")<100)
    {
        message_vision("$N瞪了你一眼，说道你凭什么让我相信你？\n",this_object(), me);
        return 1;
    }
    if(me->query("combat_exp")>400000) 
    {
        message_vision("$N说道：哎~~  不要和老夫开玩笑了！您是做大事的，这点小事怎敢劳烦大侠！\n",this_object(), me);
        return 1;
    }
    if(me->query("shou_xincha")==1)
    {
        message_vision("$N问道：这位" + RANK_D->query_respect(me) + "是否还有其他的任务未完成吧？\n",this_object(), me);
        return 1;
    }    
    if(me->query("shou_xincha")==2)
    {
        message_vision("$N说道：我不是给过你茶票了吗？难道你把它丢了？\n",this_object(), me);
        return 1;
    }  
    if(me->query("shou_xincha")==0)
    {
        switch(random(6)) //随机分配六个工作
        { 
        case 0: 
        ob = new(__DIR__"obj/cp1");
        message_vision("$N微笑道：好吧，沉香镇南街附近的农民有一批新茶，你去取回来！\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"品茶居士给了你一张茶票。\n");
        break;

        case 1: 
        ob = new(__DIR__"obj/cp2");
        message_vision("$N微笑道：好吧，冰上之镇闹市附近的农民有一批新茶，你去取回来！\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"品茶居士给了你一张茶票。\n");
        break;
        
        case 2: 
        ob = new(__DIR__"obj/cp3");
        message_vision("$N微笑道：好吧，武当山脚下附近的农民有一批新茶，你去取回来！\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"品茶居士给了你一张茶票。\n");
        break;

        case 3: 
        ob = new(__DIR__"obj/cp4");
        message_vision("$N微笑道：好吧，大昭寺附近的农民有一批新茶，你去取回来！\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"品茶居士给了你一张茶票。\n");
        break;

        case 4: 
        ob = new(__DIR__"obj/cp5");
        message_vision("$N微笑道：好吧，万梅山庄附近的农民有一批新茶，你去取回来！\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"品茶居士给了你一张茶票。\n");
        break;

        case 5: 
        ob = new(__DIR__"obj/cp6");
        message_vision("$N微笑道：好吧，东海海边附近的农民有一批新茶，你去取回来！\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"品茶居士给了你一张茶票。\n");
        break;
        } 
    }

} 

int accept_object(object me, object ob)
{
    int  exp, pot, score, money;
    object mon;

    me = this_player();
    if((string)ob->query("id")!="xincha")
    {
        return 1;
    }
    if(me->query("shou_xincha")==0)
    {
        message_vision("$N说道用奇异的眼神看着你说道：我给过你那么多任务么？\n",this_object(), me);
        return 0;
    }
    if(me->query("shou_xincha")!=2)
    {
        message_vision("$N说道：哎？我记得好像没有让你去取新茶，你开什么玩笑？\n",this_object(), me);
        return 0;
    }
    if((string)ob->query("id")=="xincha")
    {
        command("say 好，这是给你的奖励！\n");
        call_out("destroying", 1, this_object(), ob); 
        exp = 100 + random(100);
        pot = exp / 2 + 1;
        score = random(10);
        money = exp / 3 + random(10);
        mon = new("/obj/money/silver");
        mon->set_amount(money);
        mon->move(me);
        me->add("potential", pot); 
        me->add("combat_exp", exp); 
        me->add("score",score);
        tell_object(me, HIY"你被奖励了：\n" NOR +
        chinese_number(exp) + HIG"点实战经验\n" NOR +
        chinese_number(pot) + HIC"点潜能\n" NOR +
        chinese_number(score) + HIM"点综合评价\n" NOR +
        chinese_number(money) + HIW"两白银\n" NOR);
        call_out("delete", 1);
        return 1;
    }    
}

int do_lost()
{
    object me;
    me = this_player();
    tell_object(me,"$N用很疑惑的眼神看着你。\n");
    if(me->query("shou_xincha")==1)
    {
        message_vision("$N说道：你丢什么？我怎么会知道？\n",this_object(), me);
        return 1;
    }
    if(me->query("shou_xincha")==2)
    {
        me->add("score", -10);
            if (present("chapiao",me)) destruct(present("chapiao",me));      
        call_out("delete",1);
        message_vision("$N说道：这点小事都办不了？．．．\n",this_object(), me);
        return 1;
    }    
}

int delete()
{
        this_player()->delete("shou_xincha");
        return 1;
}
