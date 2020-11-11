#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","洞底");
  set("long",@LONG
你隐约能听到有人愤怒的惊呼声。声音很短促，然后一切又归于平静。 
但平静并不代表安全，黑暗中仍然到处都潜伏着危险！ 你发觉右边是一扇
门（rightdoor）。有笑声从门后发出来的，笑声突然变成了令人心跳的呻
吟声。声音妖媚而诱惑，简直令人无法拒绝。你再向左移动，又找着另一扇
门（leftdoor）。这扇门后没有声音。
LONG
  );
  set("item_desc", ([
            "leftdoor": "这门和右边那扇一模一样。\n",
            "rightdoor": "你虽然什么也看不见，但心跳已经加快了...\n"

    ]) );
	set("no_magic",1); set("no_dazuo",1);

    set("objects",([
        	__DIR__"npc/bianfu" : 1,			
       	]) );
//(3310,0,-30)
    set("coor/x",3310);
	set("coor/y",0);
	set("coor/z",-30);
	setup();
}
void init()
{

add_action("do_open","open");
}
int do_open(string arg)
{
        object room;
        object me;
		int urkee;
        if(!arg || arg=="")
        {
                write("你要打开什么？\n");
                return 1;
        }
        if( arg == "rightdoor")
        {
         me = this_player();
         message_vision(HIR"$N刚一推开门，就有一个人投入你的怀抱。将你拉了过去！\n"NOR, me);
         room = load_object(__DIR__"room1");
	     me->move(room);
         return notify_fail("");
	    }
        if( arg == "leftdoor")
        {
         me = this_player();
		 urkee=me->query("eff_kee");
         message_vision(HIR"$N刚一推开门，一阵冷箭以快得不能再快的速度射了出来。\n"NOR, me);
         message_vision("("+RED"$N满身鲜血，已经有如风中残烛，随时都可能断气。"+NOR+")\n", me);
         me->receive_wound("kee",urkee+1000);
//	     me->die();
         return notify_fail("");
	    }
       return 1;
        
}


