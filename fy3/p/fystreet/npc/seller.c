// seller.c zip@hero 2000.1.27 �ۻ�Ա
inherit NPC;
void create()
{	set_name("�ۻ�Ա",({"seller"}));
	set("gender","Ů��");
	set("long","�����̳����ۻ�Ա�������������(book)�Ҿߡ�\n");
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
{  command("say ��������Ҿ���ȫ��ÿ��ֻҪ200gold��400�ۺ����ۣ�������㿴��");
   return 1;
}
int do_book(string arg)
{ object ob,gold;
  object me=this_player();
  gold=present("gold_money",this_player());
  if(!me->query("roomid")) return notify_fail("�ۻ�Ա˵��������û���Լ��ķ����أ����˼Ҿ����Ķ��Ű���\n");
  if(!arg) return notify_fail("�ۻ�Ա˵������Ҫ���ʲô�Ҿߣ�\n");
  if(!objectp(ob=present(arg,environment(me)))) return notify_fail("�ۻ�Ա˵������Ҫ���ʲô�Ҿߣ�\n");
  if(!ob->query("is_jiaju"))
   {message_vision("$N�ɴ����۾���ֵؿ���$nһ�ۣ��Գ�Ц��������Ҫ�򡣡���"+ob->query("name")+"����\n",this_object(),me);
    return 1;}
  if(me->query("score")<400) return notify_fail("�ۻ�Ա˵���������ۺ����۲����ˡ�\n");
  if(!gold||gold->query_amount()<200) return notify_fail("�ۻ�Ա˵�������Ľ��Ӳ����ˡ�\n");
  me->add("score",-400);gold->add_amount(-200);
  me->add("jiaju",1);
  message_vision("$N����һ��"+ob->query("name")+"��\n",me);
  command("say �ã�������͸����͹�ȥ��");
  destruct(ob);
return 1;
}