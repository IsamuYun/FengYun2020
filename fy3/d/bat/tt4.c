#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "天梯尽头 ");
        set("long", @LONG
这里有两扇门，一扇（door1）通向外面，是活路；还有一扇（door2）门是死
路—门外就是看不见底的万丈探蹦，只要一脚踏下，就万劫不复了！没有人知道哪
扇门外是活路。你可以自己选择去开门，但只要一开了门，就非走出去不可。
LONG        );
        set("exits", ([ 
  "down" : __DIR__"tt3",
]));       
  set("item_desc", ([
            "door1": "这门和右边那扇一模一样。\n",
            "door2": "你虽然什么也看不见，但心跳已经加快了...\n"
    ]) );
        set("coor/x",3300);
        set("coor/y",20);
        set("coor/z",20);
        set("no_magic",1);
        setup();
}
void init()
{
add_action("do_open","open");
add_action("do_say","say");
}
int do_open(string arg)
{
               object me;
                int urkee;
        if(!arg || arg=="")
        {
                write("你要打开什么？\n");
                return 1;
        }
if( arg == "door1")
        {
         me = this_player();
                 urkee=me->query("eff_kee");
         message_vision(HIR"$N刚一推开门，突然感到一阵茫然，四处一片寂静。\n"NOR, me);
         message_vision("("+RED"$N满身鲜血，已经有如风中残烛，随时都可能断气。"+NOR+")\n", me);
         me->receive_wound("kee",urkee+1000);
                    } else
        if( arg == "door2")
        {
         me = this_player();
                 urkee=me->query("eff_kee");
         message_vision(HIR"$N刚一推开门，一阵冷箭以快得不能再快的速度射了出来。\n"NOR, me);
         message_vision("("+RED"$N满身鲜血，已经有如风中残烛，随时都可能断气。"+NOR+")\n", me);
         me->receive_wound("kee",urkee+1000);
            }
       return 1;
}

int do_say(string arg)
{
object me;
object room;
me=this_player();
 if(arg == "我来过，活过，爱过！")
{message_vision(HIY "\n$N推开了门，眼前现出灿烂无比的夕阳... \n"NOR,this_player());
room = load_object(__DIR__"side");
             me->move(room);
return 1;
}
}