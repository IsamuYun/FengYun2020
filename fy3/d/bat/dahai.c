#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short","大海");
  set("long",@LONG
你正处在茫茫大海之中。你极目远望，只见海天一线，周围连个黑点都没有。
耳边只有海浪（wave）的拍打声。
LONG
  );
  set("item_desc", ([
            "wave":BLU "海浪就象是一头头恶狼，唑咬着你的船！\n" NOR,
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
         write(BLU "海浪就象是一头头恶狼，唑咬着你的船！\n" NOR);
         if( (int)query("trigger")==10) 
		 {
          delete("trigger");

          me = this_player();
          message("vision", 
BLU"突然间，你的船触礁了！一个大浪打来，你被抛入空中．．．\n"NOR,me );
          room = load_object(__DIR__"anbian");
	      me->move(room);
          return notify_fail("");
		 }
		 return 1;
		}
}

