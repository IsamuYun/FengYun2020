//XXDER
inherit ITEM;
void create()
{
   set_name("����ƿ", ({ "yu ping", "bottle", "��ƿ" }) );
   set_weight(500);
   set_max_encumbrance(100);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "��");
      set("long", "һ�������������ɵ�Сƿ�ӣ�ƿ�����ܷ�ġ�\n");
      set("value", 0);
   }
}

int is_container() { return 1; }

void init()
{
   add_action("do_open", "open");
}

int do_open(string arg)
{
   object me, item, ob;

   me = this_player();
   ob = this_object();
   if (!arg || (arg != "yu ping" && arg != "����ƿ"))
      return 0; 
   if(ob->query_temp("marks/opened"))
      return 0;
   message_vision("$NС������ش򿪰���ƿ��\n",me);
   set("long", "һ�������������ɵ�Сƿ�ӡ�\n");
   item = new(__DIR__"medicine");
   item->move(ob);   
   ob->set_temp("marks/opened", 1);
   return 1;
   
}
