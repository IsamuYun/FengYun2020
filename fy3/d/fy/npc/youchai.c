inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int give_him();

void create()
{
        set_name("飞毛腿", ({ "you chai", "you"}) );
        set("title","风云邮差");
        set("gender", "男性" );
        set("age", 46);
        set("agi",30);
        set("str", 22);
        set("per", 28);
        set("int",24);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 40);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_atman", 5000);
        set("atman", 5000);
        set("long",
"风云城的邮差，据说年轻的时候跑的非常快。所以有飞毛腿的外号。\n"
        );
        set("chat_chance_combat", 20);
        set("combat_exp", 1000000);
        set_skill("dodge", 110);
        set_skill("move",140);
        set_skill("force", 140);
        set_skill("sword", 110);
        set_skill("literate", 120);
        set_skill("unarmed",110);
        set_skill("yiyang-zhi", 110);
        map_skill("force", "tianlong-shengong");
        map_skill("unarmed", "yiyang-zhi");
        set("inquiry", 
([ "密函" : (: give_him :), "letter" : (: give_him :)  ]));
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
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N说道：“每天要送的信件太多了．．。”\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N望了$n一眼，问道：你能帮助吗？我不会亏待你的．．。\n",this_object(),ob);
                        break;
        }
}

int give_him()
{
        string *order1 = ({"/d/dali/quan5","/u/wudang/farm4","/u/wudang/farm5","/d/dali/quan6","/d/manglin/center2","/u/wudang/farm6","/d/manglin/center4","/d/dali/quan7","/u/wudang/farm7","/d/manglin/center1","/d/dali/quan2","/u/wudang/farm9","/d/dali/quan3"});
        string time11;
        object me , obj ,room1;
        int xintime,m,s;
        me = this_player();        
        if(me->query("lettertime") > time()) 
           {
    tell_object(me,"飞毛腿说道：你的上一封信还没送到，怎么还来问我要？！\n");
            return 1;
           }
        obj = new("/d/dali/obj/letter");
        xintime = 100+me->query("kar")*10+random(50);
        s = xintime % 60;             m = xintime / 60;
        room1 = load_object(order1[random(16)]);
        me->set("lettertime",time()+xintime);
        obj->set("pname",me->query("name"));
        time11 = "飞毛腿说道：";
        time11 += room1->query("short");
        time11 += "有一封密函，一定要在"HIW;
        time11 += chinese_number(m) + "分";
        time11 += chinese_number(s) + "秒" ;
        time11 += NOR "内送交给" HIW ;
        time11 += obj->query("toname") + NOR"。我先送你去那里。\n";
        tell_object(me, time11);
        me->set("letter",time()+600+random(300));
        me->add("giveletter",1);        
        obj->move(me);
        me->move(room1);
        tell_object(me,"一个神秘蒙面人给了你一封密函。\n");
        me->set_temp("nofly",1);
        me->set_temp("noburn",1);
        return 1;
}

int accept_object(object who, object ob)
{
  int  exp, pot,score;
  exp = random(200)+300;
  pot = exp / 10;
  score = exp / 100 + random(10) ;
  if(ob->query("name") == "回函")
    {
     who->delete("lettertime");
     if(!(ob->query("pname") == who->query("name")) )
      {
       write("飞毛腿说道:这种来历不明的东西我没收了！\n");
       return 1;
      }
     command("nod");     
     command("say 好! 谢谢你帮助我。我说过我不会亏待你的！\n");
        who->add("LQUEST",1);
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        who->delete_temp("lettertime");
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"+
        chinese_number(score) + "点综合评价。\n" NOR);
        return 1;
    }
  tell_object(who,"飞毛腿说道：谢赏！\n");
  return 1;
}

