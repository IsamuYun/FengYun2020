inherit ROOM;
#include <command.h>
#include <ansi.h>

void create()
{
        set("short", "榕树林");
        set("long", @LONG
走过沼泽,就看到了一片茂密的榕树林，高大的榕树高耸入云，无数的藤
条从树上垂下。茂密的榕树叶把阳光尽数遮住，让人有种阴森的感觉。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "north" : __DIR__"studyroom",
//  "south" : __DIR__"xting",
    "east" : __DIR__"wenquan",
  "west" : __DIR__"edge",
   ]));

   set("item_desc", ([
      "tiao" : "一条条手腕粗细的藤条从高大的榕树上垂下你似乎可以利用他爬(climb)上去。\n",
      "藤条" : "一条条手腕粗细的藤条从高大的榕树上垂下你似乎可以利用他爬(climb)上去。\n",
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
   if(!arg || arg != "藤条" && arg != "tiao") return 0; 
   mlvl = (int)me->query_skill("move");
   if(mlvl < 50)
      message_vision("$N抓住藤条试图爬上去，但看来没希望爬上去。\n", me);
   else{
      message_vision("$N身手矫健地抓着突出的藤条灵巧地爬上了高大的榕树。\n", me);
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
   message_vision("一阵微风拂过"+obj->name()+"缓缓的升了起来。\n\n" , me);
   message_vision("突然一阵劲风，"+me->name()+"手中的线断了，"+obj->name()+"晃晃悠悠地越飞越高，慢慢不见了。 \n",me);
   destruct(obj);
   return; 
}
