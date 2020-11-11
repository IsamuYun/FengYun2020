#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ƺ");
        set("long", @LONG
��ͩ����ٲȻһ��СС��գ�������ͩ��Ҷʪ���̺�ҶҶ���ġ���
�������飬΢��������ڶ���һ��ʯ��������ʯ�ʶ˶������ذ���С��ƺ��
�룬С��������Ϣ�ش����������˸�Ȧ��������һ�����µ�����Ӻ����ϴ�
�����㲻�ɵþ��þ���Ϊ֮һ��һ�䲻֪���˵�ʫӿ�����У���Ҷ��ˮ��
Ȼȥ ������ط��˼� ����
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"grassland",
	]) );

	set("item_desc", ([
           "river" : "һ���峺��С�ӣ�������С�����ζ���\n",
           "С��" : "һ���峺��С�ӣ�������С�����ζ���\n",
	]) );
	
	set("outdoors","taoyuan");
        set("coor/x",220);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void fish_notify(object obj, int i)
{
   object me, room, fish, *inv, bait;

   me = this_player();
	
   switch (i) { 
   case 0:
      bait = present("qiu yin", obj);
      if(!objectp(bait)) {
      message("vision",me->name() + "�ͳ���" + obj->name() + "�ַ��˻�ȥ��\n", environment(me), me);
      tell_object(me, obj->name() + "��û�ж���ô���Ե����� ? \n");
      }
   else {
      message_vision("$N�Ӷ���һ��," + obj->name() + "�ڿ��л���һ��Ư���Ļ���, �㹳������ˮ��. \n" , me);
      destruct(bait);
      remove_call_out("do_fishing");              
      me->start_busy(2);
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
