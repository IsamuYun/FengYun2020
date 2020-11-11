#include <room.h>
inherit ROOM;
int do_dash(string arg);
void create()
{
  set("short","灌木林");
  set("long",@LONG
灌木林非常的阴暗潮湿，还有海腥味。你对这里有这么大一片
灌木林(bush)感到非常吃惊。四周似乎根本没有路，四周长满了半
人高的杂草。
LONG
  );
  set("exits",([
            "west" :"/d/tieflag/searoad1",
               ]));
  set("item_desc", ([
            "bush": "这片灌木林太深了,要想过去恐怕只有硬往前闯（dash）了。\n",
            "灌木林": "这片灌木林太深了,要想过去恐怕只有硬往前闯（dash）了。\n"

    ]) );

    set("outdoors", "bat");
	set("no_magic",1);

    set("coor/x",1100);
	set("coor/y",-290);
	set("coor/z",-10);

	setup();
//    replace_program(ROOM);
}

void init()
{

add_action("do_dash","dash");
}
int do_dash(string arg)
{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("你要往哪儿钻？\n");
                return 1;
        }
        if( arg == "bush" || arg == "灌木林")
        {
         me = this_player();
		 if(me->query("force")>300)
		 {
          message_vision("$N使劲往灌木林中一闯，结果一个跟头翻了进去！\n", me);
          room = load_object(__DIR__"lin2");
	      me->move(room);
		  me->set("force",0);
		  me->set("mana",0);
	      me->set("atman",0);
  
          return notify_fail("");
		 }
		 else
		 {
          message_vision("$N累得气喘吁吁，也没有闯出条路来！
                        \n", me);		  
		  return 1;
		 }
        }
		else
		{
                write("你要往哪儿钻？\n");
                return 1;
		
		}
        
}
