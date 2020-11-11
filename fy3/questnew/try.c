// waiter.c

inherit NPC;
int give_him();
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("巴天石", ({ "batianshi" }) );
        set("gender", "男性" );
        set("age", 81);
        set("title", HIY "大理司空" NOR);
        set("long",
                "这是个中年汉子，目下在大理国位居司空。。\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",50);
        set_skill("dodge",50);
        set("inquiry", ([
                "挖药" : (: give_him :),
                "wayao" : (: give_him :),
        ]));
        setup();
        //carry_object("/obj/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N说道：“大理国库正缺少一些药材．．。”\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N望了$n一眼，问道：你对挖药感兴趣吗？．．。\n",this_object(),ob);
                        break;
        }
}
int give_him()
{
        object me , obj;
        me = this_player();
        if( !query("given")) {
        obj = new("/questnew/yaochu");
        message_vision("$N说道：既然你对挖药感兴趣，我就把这项重要的工作交付给你了，
巴天石给了$n一把药锄。\n",this_object(), me);
        obj->move(me);
        set("given",1);
        return 1;
        }
        return 0;
}


int accept_object(object who, object ob)
{
  int  exp, pot, gong, score;
        exp = random(200)+100;
        pot = exp / 10 + 1;
        gong = exp / 50 + 2;
        score = exp / 50 +5;
        if(!(who->query("class") == "dali") )
        {
                write("巴天石说道:你不是大理弟子，这种来历不明的东西我不要！\n");
                return 1;
        }
if(ob->query("name") == "千年人参")
        {
command("say 你为国家做出了贡献，给你应该得到奖励！\n");
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        who->add("gongxian",gong);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"+
        chinese_number(gong) + "点对大理国的贡献点\n"+
        chinese_number(score) + "点综合评价。\n" NOR);
        return 1;
        }
if(ob->query("name") == "成型淮山")
        {
command("say 你为国家做出了贡献，给你应该得到奖励！\n");
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        who->add("gongxian",gong);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"+
        chinese_number(gong) + "点对大理国的贡献点\n"+
        chinese_number(score) + "点综合评价。\n" NOR);
        return 1;
        }
if(ob->query("name") == "何首乌精")
        {
command("say 你为国家做出了贡献，给你应该得到奖励！\n");
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        who->add("gongxian",gong);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"+
        chinese_number(gong) + "点对大理国的贡献点\n"+
        chinese_number(score) + "点综合评价。\n" NOR);
        return 1;
        }
if(ob->query("name") == "珍贵北芪")
        {
command("say 你为国家做出了贡献，给你应该得到奖励！\n");
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        who->add("gongxian",gong);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"+
        chinese_number(gong) + "点对大理国的贡献点\n"+
        chinese_number(score) + "点综合评价。\n" NOR);
        return 1;
        }
        tell_object(who,"巴天石说道：大理国库会需要这种枯枝烂草吗？\n");
        return 0;
}