inherit NPC;
void create()
{	set_name("����С��",({"waitress","bar waitress"}));
	set("gender","Ů��");
	set("age",22);set("cost",0);
	set("attitude","heroism");
	set_temp("hslj",10);
       set("per",30);
	set_temp("tcpg",15);
	set_temp("wly",50);

setup();
carry_object("/obj/cloth")->wear();
}
void init() {add_action("do_order","order");}

int do_order(string arg)
{ object ob,me,mee,gold;
  me=this_player();mee=this_object();
  if(!arg||arg=="")
  {message_vision("$N΢Ц����$n����Ҫ��ʲô��\n",mee,me);return 1;}
  if(arg=="menu")
  {new(__DIR__"obj/menu")->move(mee);
   command("give menu to "+me->query("id"));return 1;}
 if(arg=="bill")
  {message_vision("$N���˸���ָ���򵥡�\n",me);
   message_vision("$N���˹�����˵�����ܹ�"+(string)mee->query("cost")+"gold��\n",mee);
   gold=present("gold_money",me);
    if(!objectp(gold)||gold->query_amount()<mee->query("cost"))
     {message_vision("$N΢Ц��˵��������gold���񲻹��ˡ�\n",mee);return 1;}
    gold->add_amount(-mee->query("cost"));mee->set("cost",0);
   message_vision("$N˵����лл��\n",mee);
   return 1;}  
  if(file_size(__DIR__"obj/"+arg+".c")==-1||mee->query_temp(arg)<1)
  {message_vision("$N΢Ц�Ŷ�$n˵����ʵ�ڶԲ����������û��"+arg+"��\n",mee,me);return 1;}
  ob=new(__DIR__"obj/"+arg);mee->add("cost",5);mee->add(arg,-1);
  message_vision("$N���˸���ָ����һ��"+ob->query("name")+"��\n",me);
  message_vision("$N����һ��"+ob->query("name")+"�������ϡ�\n",mee);
  ob->move(present("dinner table",environment(mee)));ob->set("amount",20);
return 1;
}
 
