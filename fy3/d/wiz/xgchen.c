inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "长孙堡");
        set("long", @LONG
这里是长孙无情的长孙堡。他却不在这里,他正在处理他的跨国公司的
业务呢!墙上显眼处挂着一块告示(gaoshi)。
LONG);
        set("item_desc", ([
                "gaoshi" : "警告大家请不要乱走。 

                            长孙无情字。\n",

]));
        set("sleep_room", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 18 */
  "south" :__DIR__"hall",
  "gc" :"/d/fy/fysquare",
]));
//         set("objects", ([ /* sizeof() == 1 */
//              "/u/chen/npc/xiaocui" : 1,
//                ]));
        set("no_steal", "1");
        set("no_fight", "1");
        setup();
        replace_program(ROOM);
}
void init()
{
      add_action("do_push","push");
}
int do_push(string arg)
{
object me,ob;
me=this_player(); 
if (me->query("id") != "chen") return 0;

 //       if( !(ob = present(arg, environment(me))) || !ob->is_character() )
  //               return notify_fail("这里没有这个人！\n");
        ob->move("d/fy/fysquare");
        message_vision(HIW"$N把$n推了出去！\n"NOR,me,ob);
        tell_room("/d/fy/fysquare","突然，"+ob->query("name")+"被长孙无情踢了出来!\n");
        return 1;
       }