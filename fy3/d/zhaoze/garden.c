inherit ROOM;
#include <command.h>
#include <ansi.h>

void create()
{
        set("short", "������");
        set("long", @LONG
�߹�����,�Ϳ�����һƬï�ܵ������֣��ߴ�������������ƣ���������
�������ϴ��¡�ï�ܵ�����Ҷ�����⾡����ס������������ɭ�ĸо���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "north" : __DIR__"studyroom",
//  "south" : __DIR__"xting",
    "east" : __DIR__"wenquan",
  "west" : __DIR__"edge",
   ]));

   set("item_desc", ([
      "tiao" : "һ���������ϸ�������Ӹߴ�������ϴ������ƺ�������������(climb)��ȥ��\n",
      "����" : "һ���������ϸ�������Ӹߴ�������ϴ������ƺ�������������(climb)��ȥ��\n",
   ]) );

 //  set("objects", ([
 //     __DIR__"npc/yan" : 1,
 //  ]) );
        set("outdoors","zhaoze");
        set("coor/x",0);
        set("coor/y",-610);
        set("coor/z",-20);
        set("coor/x",0);
        set("coor/y",-610);
        set("coor/z",-20);
        setup();
}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
   object me, room;
   int mlvl;
   
   me = this_player();
   if(!arg || arg != "����" && arg != "tiao") return 0; 
   mlvl = (int)me->query_skill("move");
   if(mlvl < 50)
      message_vision("$Nץס������ͼ����ȥ��������ûϣ������ȥ��\n", me);
   else{
      message_vision("$N���ֽý���ץ��ͻ�����������ɵ������˸ߴ��������\n", me);
      room = find_object(__DIR__"midtree");
      if(!objectp(room)) room=load_object(__DIR__"midtree");
      me->move(room);
   }
   return 1;
}

void kite_notify(object obj, int i)
{
   object  me, room;
   int j;
        
   me = this_player();
   message_vision("һ��΢�����"+obj->name()+"����������������\n\n" , me);
   message_vision("ͻȻһ�󾢷磬"+me->name()+"���е��߶��ˣ�"+obj->name()+"�λ����Ƶ�Խ��Խ�ߣ����������ˡ� \n",me);
   destruct(obj);
   return; 
}
