inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
���ֵ��˴˴��𽥱��ϡ����������ǰ��Ȼ����һ��ǧ����䡢�����Ե�ɽ�壬
Χ��һ���Ĺȣ�����һ����̶��Ȫˮ�ӷ�䱼�����£�����й��ֱ����̶����ֻ��β
�͵�Ұ�ã�����̶�����еĺ�ˮ���˴���������ʪ�������ķΣ�����ȴ�������κ���
�Եĳ�·����������ֻ���Ĵ�תת���ˡ�
LONG
        );
        set("item_desc", ([
           "��̶":  "��̶�������ף�����С��СϺ����������������\n",
           "pond":  "��̶�������ף�����С��СϺ����������������\n",
        ]));
        set("exits", ([ /* sizeof() == 4 */
   "south" : __DIR__"taolin1",
]));
        set("outdoors","taoyuan");
        set("coor/x",150);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}
void init()
{
   add_action("do_around", "around");
}

int do_around(string arg)
{
   object me, room;

   me = this_player();
   tell_object(me, "��ת��תȥ��Ҳû�ҵ����ڣ�������·����\n\n");
   room = find_object(__DIR__"valley2");
   if(!objectp(room)) room=load_object(__DIR__"valley2");
   me->move(room);

   return 1;
}

void fish_notify(object obj, int i)
{
   object me, room, fish, *inv, bait;

   me = this_player();
	
   switch (i) { 
   case 0:
      bait = present("dead qu", obj);
      if(!objectp(bait)) {
      message("vision",me->name() + "�ͳ���" + obj->name() + "�ַ��˻�ȥ��\n", environment(me), me);
      tell_object(me, obj->name() + "��û�ж���ô���Ե����� ? \n");
      }
   else {
      message_vision("$N�Ӷ���һ��," + obj->name() + "�ڿ��л���һ��Ư���Ļ���, �㹳������ˮ��. \n" , me);
      destruct(bait);
      remove_call_out("do_fishing");              
      call_out("do_fishing", 5, me);
      }
   break;
   }
   return;
}

void do_fishing(object me)
{
   object 	fish;

   if(me && environment(me) == this_object()) {
   message_vision("$N�ܿ��ֳ�����һ�����, " , me);
   switch (random(3)) {
      case 0:
         message_vision("ȴʲô��û������ ! \n", me);
         break;
      case 1:
         message_vision("ʲô��û������ , ���ȴ������� !!  \n", me);
         break;
      case 2:
         message_vision("�㹳�ϵ���һ������ !!  \n", me);
         fish = new(__DIR__"obj/fish");
         fish->move(me);
         break;
      }
   }
   return;
}
