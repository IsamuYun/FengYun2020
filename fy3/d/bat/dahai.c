#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short","��");
  set("long",@LONG
��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ�����ڵ㶼û�С�
����ֻ�к��ˣ�wave�����Ĵ�����
LONG
  );
  set("item_desc", ([
            "wave":BLU "���˾�����һͷͷ���ǣ���ҧ����Ĵ���\n" NOR,
    ]) );


    set("outdoors", "bat");
	set("no_magic",1); set("no_dazuo",1);


    set("coor/x",3000);
	set("coor/y",0);
	set("coor/z",0);

	setup();
//    replace_program(ROOM);
}
void init()
{
  add_action("do_look", "look");
}


void reset()
{
        ::reset();
        delete("trigger");
}
int do_look(string arg)
{
        object room;
        object me;
        if( arg == "wave" )
        {
   	     add("trigger", 1);
         write(BLU "���˾�����һͷͷ���ǣ���ҧ����Ĵ���\n" NOR);
         if( (int)query("trigger")==10) 
		 {
          delete("trigger");

          me = this_player();
          message("vision", 
BLU"ͻȻ�䣬��Ĵ������ˣ�һ�����˴������㱻������У�����\n"NOR,me );
          room = load_object(__DIR__"anbian");
	      me->move(room);
          return notify_fail("");
		 }
		 return 1;
		}
}

