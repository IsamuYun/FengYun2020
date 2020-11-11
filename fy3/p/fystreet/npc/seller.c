// seller.c zip@hero 2000.1.27 售货员
inherit NPC;
void create()
{	set_name("售货员",({"seller"}));
	set("gender","女性");
	set("long","风云商场的售货员，你可以向她定(book)家具。\n");
	set("age",22);
	set("combat_exp",9999999);
	set("attitude","heroism");
	setup();
	carry_object("/obj/cloth")->wear();
}
void init()
{  add_action("do_list","list");
   add_action("do_book","book");}

int do_list()
{  command("say 我们这儿家具齐全，每件只要200gold与400综合评价，您请随便看。");
   return 1;
}
int do_book(string arg)
{ object ob,gold;
  object me=this_player();
  gold=present("gold_money",this_player());
  if(!me->query("roomid")) return notify_fail("售货员说道：您还没有自己的房子呢，买了家具往哪儿放啊？\n");
  if(!arg) return notify_fail("售货员说道：您要买点什么家具？\n");
  if(!objectp(ob=present(arg,environment(me)))) return notify_fail("售货员说道：您要买点什么家具？\n");
  if(!ob->query("is_jiaju"))
   {message_vision("$N瞪大了眼睛奇怪地看了$n一眼，吃吃笑道：“您要买。。。"+ob->query("name")+"？”\n",this_object(),me);
    return 1;}
  if(me->query("score")<400) return notify_fail("售货员说道：您的综合评价不够了。\n");
  if(!gold||gold->query_amount()<200) return notify_fail("售货员说道：您的金子不够了。\n");
  me->add("score",-400);gold->add_amount(-200);
  me->add("jiaju",1);
  message_vision("$N定下一套"+ob->query("name")+"。\n",me);
  command("say 好，我们这就给您送过去。");
  destruct(ob);
return 1;
}