//XXDER
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ܴ�������������ˮ���ϣ����Բ����ߡ����������Ľż�������
����ˮ�棬΢��Ϯ������������������գ��������˵���һ������ᡣ������
�������µ�ˮ�����е�������ȥ����Զ����С�ŵ�ӳ��ˮ�У������￴ȥ����һ
�����¡�
LONG
        );

   set("exits", ([ /* sizeof() == 4 */
      "down" : __DIR__"northpond",
   ]));

   set("outdoors", "qingping");
   set("coor/x",190);
        set("coor/y",2010);
        set("coor/z",10);
   setup();
}

int fish_notify(object obj, int i)
{
   object me, room, fish, *inv, bait;
   int llvl;

   me = this_player();
   llvl = (int)me->query("kar");
	
   switch (i) { 
   case 0:
      bait = present("qiu yin", obj);
      if(!objectp(bait)) {
      message("vision",me->name() + "�ͳ���" + obj->name() + "�ַ��˻�ȥ��\n", environment(me), me);
      tell_object(me, obj->name() + "��û�ж���ô���Ե����� ? \n");
      }
   else {
      message_vision("$N���������Ͼ����Ŀ�ʼ������ \n" , me);
      me->start_busy(3);
      if(llvl > 15) {
         if(random(100) < llvl) {
            tell_object(me, "��������ע�⵽��ͷѩ�׵�ʯͷ���ƺ���һ��ڰߡ�\n");
            me->set_temp("marks/bridge", 1);
         }
      }
      else {
         if(random(300) < llvl) {
            tell_object(me, "��������ע�⵽��ͷѩ�׵�ʯͷ���ƺ���һ��ڰߡ�\n");
            me->set_temp("marks/bridge", 1);
         }
      }
      destruct(bait);
      remove_call_out("do_fishing");              
      call_out("do_fishing", 5, me);
      }
   break;
   }
   return 0;
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
         message_vision("�㹳�ϵ���һ���� !!  \n", me);
         fish = new(__DIR__"obj/fish");
         fish->move(me);
         break;
      }
   }
   return;
}

