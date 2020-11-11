// banker.c

#include <ansi.h>

inherit NPC;
inherit F_BANKOWNER;
int ask_for();

void create()
{
        set_name("南宫十三郎", ({ "nangong" }) );
        set("title", RED "钱庄掌柜" NOR);
        set("gender", "男性" );
        set("richness",100000);
        set("age", 52);
        set("long",
                
                "中原南宫世家，家财万贯，产业不可胜数，南宫十三也是南宫世家
的族人\n");

        set("attitude", "friendly");

        set("max_atman", 1000);         set("atman", 1000);             
set("atman_factor", 3);
        set("max_force", 1000);         set("force", 1000);             
set("force_factor", 3);
        set("max_mana", 1000);          set("mana", 1000);              
set("mana_factor", 3);
    set("inquiry", ([
                "新手套装" : (: ask_for :),
        ]) );

        set_skill("dodge", 10);
        set_skill("parry",100);
        setup();
        carry_object("/obj/cloth")->wear();
     //   add_money("gold", 1);
}

void init()
{
        ::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
        add_action("do_loan","loan");
}

int accept_object(object who, object ob)
{
  object silk;
  if(ob->query("id") == "goodguancai")
        {
command("say 感谢这位" + RANK_D->query_respect(who)+ "远道把棺材送来，真没想到棺材店老板有这么好的手艺，
这是给你的感谢！\n");
silk = new("/questobj/big");
silk->move(who);
        tell_object(who,"南宫十三郎给你一个"+silk->query("name")+"。\n");
//silk->move(this_object());
//command("give jin-nang to " + who->query("id"));
who->add("bigtasks",1);
        return 1;
        }
 if(ob->query("pname") != who->query("name")) 
   {
    tell_object(who,query("name") + "说道：这不是你的，没收。\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(who->query("letter") < time())
   {
    tell_object(who,query("name") + "说道：哎，晚了，你来晚了！\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(ob->query("toname") == query("name"))
  {
   command("say 感谢这位远道把密函送来，这是给你的回函,切记要保管好！！\n");
   who->set_temp("nofly",0);
   silk = new("/d/dali/obj/huihan");
   silk->set("pname",who->query("name"));
   silk->move(who);
   return 1;
  }
        tell_object(who,"南宫十三郎说道：这不是我想要的。\n");
        return 0;
}

int ask_for()
{
	
	object ob,me,obj;
	me = this_player();
	ob = this_object();

	if (me->query("marks/newbie"))
		{
		message_vision("$n疑惑着对着$N说道：你不是已经拿过新手套装了？\n",me,ob);
		return 1;
		}
	if (!me->query_temp("askfornewbie"))
		{
		message_vision("$n疑惑着对着$N说道：你想做什么？\n",me,ob);
		return 1;
		}
	else 	if (me->query_temp("askfornewbie")>0 && me->query_temp("askfornewbie") < 2)
		{
		me->set_temp("askfornewbie",2);
		message_vision(me->query("name")+"对着南宫十三郎说道：听说十三先生欠了天机老人的一百两银子，是否真有此事？\n"+
"南宫十三郎很疑惑地看着"+me->query("name")+"。\n南宫十三郎回答"+me->query("name")+"：这一百两银子，早先已经托我哥十二郎还于天机老头了，怎么这老头不记得了？\n",me);
		return 1;
		}
	else if (me->query_temp("askfornewbie")>3 && me->query_temp("askfornewbie") < 5)
	{
	me->set_temp("askfornewbie",7);
	message_vision(me->query("name")+"对着南宫十三郎说道：原来真个是天机老人搞错了，他让我特地来给十三先生道个歉。\n南宫十三郎冲着"+me->query("name")+"笑了笑：那老头子竟然还来跟我来这一套，\n都一把年纪了。好了，没事了，你可以回去交差了！\n",me);
	return 1;
	}
	message_vision("$n疑惑着对着$N说道：你还在这里做什么？\n",me,ob);
	return 1;

}


